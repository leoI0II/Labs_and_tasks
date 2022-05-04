#include<iostream>

class SmallAllocator {
private:
#pragma pack(push, 1)
    struct data_block_manager{
        int size;
        bool is_available;
    };
#pragma pack(pop)
        char mem[1048576];
        int used;
        char* next_to_use;
public:
        SmallAllocator() : used(0) { next_to_use = (char*)mem; }

        void *Alloc(unsigned int required_size) {
            /*
                1. Define a data_block_manager variable - current_location = mem, init
                2. Loop (while) current_location != next_to_use
                    2.1. Check if current_location is available
                        2.1.1 Check if current_location size is greater/equal to required_size
                            2.1.1.1. We found a data block to use
                            2.1.1.2. Manage block with current_location var (is_available = 0, size = required_size)
                            2.1.1.3. Pointer to return = (void*)current_location + sizeof(data_block_manager)
                            2.1.1.4. Break the loop and return
                    2.2. Current_location = (void*)current_location + sizeof(data_block_manager) + current_location->size
                3. If we are here, we did not find a block of data
                    3.1. Current_location (in that moment = next_to_use) is not more available (0), size = required_size
                    3.2. next_to_use = (void*)current_location + sizeof(data_block_manager) + current_location->size(required_size)
                4. Return (void*)current_location + sizeof(data_block_manager)
            */

            if (used + sizeof(data_block_manager) + required_size >= 1048576){
                return nullptr;
            }

            data_block_manager* current_location = (data_block_manager*)mem;
            // void* return_pointer = nullptr;
            
            while (current_location != (data_block_manager*)next_to_use){
                if (current_location->is_available){
                    if (current_location->size >= required_size){
                        current_location->is_available = 0; current_location->size = required_size;
                        used += required_size + sizeof(data_block_manager);
                        // return_pointer = (void*)current_location + sizeof(data_block_manager);
                        return (void*)current_location + sizeof(data_block_manager);
                    }
                }
                current_location = (data_block_manager*)((void*)current_location + sizeof(data_block_manager) + current_location->size);
            }
            current_location->is_available = 0; current_location->size = required_size;
            used += required_size + sizeof(data_block_manager);
            next_to_use = (char*)((void*)current_location + sizeof(data_block_manager) + required_size);
            return (void*)current_location + sizeof(data_block_manager);
        }
        
        void *ReAlloc(void *pointer, unsigned int new_required_size) {
            /*
                1. Use Free(pointer) function
                2. Use Alloc(new_required_size) function
                3. Copy old data to new data block
            */
            void* new_data_block = Alloc(new_required_size);
            Free(pointer);
            int old_size = ((data_block_manager*)((void*)pointer - sizeof(data_block_manager)))->size;
            int i = 0;
            char* tmp = (char*)new_data_block;
            if (old_size >= new_required_size)
                while (i++ < new_required_size) { *tmp++ = *(char*)pointer++; }
            else
                while (i++ < old_size) { *tmp++ = *(char*)pointer++; }

            return new_data_block;
        }
        
        void Free(void *pointer) {
            /*
                1. pointer is now available (1)
                2. Return
            */
            data_block_manager* to_free = (data_block_manager*)(pointer - sizeof(data_block_manager));
            to_free->is_available = 1;
            return;
        }
};


int main()
{

    SmallAllocator A1;
    int * A1_P1 = (int *) A1.Alloc(sizeof(int));
    A1_P1 = (int *) A1.ReAlloc(A1_P1, 2 * sizeof(int));
    A1.Free(A1_P1);
    SmallAllocator A2;
    int * A2_P1 = (int *) A2.Alloc(10 * sizeof(int));
    for(unsigned int i = 0; i < 10; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < 10; i++) if(A2_P1[i] != i) std::cout << "ERROR 1" << std::endl;
    int * A2_P2 = (int *) A2.Alloc(10 * sizeof(int));
    for(unsigned int i = 0; i < 10; i++) A2_P2[i] = -1;
    for(unsigned int i = 0; i < 10; i++) if(A2_P1[i] != i) std::cout << "ERROR 2" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 3" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, 20 * sizeof(int));
    for(unsigned int i = 10; i < 20; i++) A2_P1[i] = i;
    for(unsigned int i = 0; i < 20; i++) if(A2_P1[i] != i) std::cout << "ERROR 4" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 5" << std::endl;
    A2_P1 = (int *) A2.ReAlloc(A2_P1, 5 * sizeof(int));
    for(unsigned int i = 0; i < 5; i++) if(A2_P1[i] != i) std::cout << "ERROR 6" << std::endl;
    for(unsigned int i = 0; i < 10; i++) if(A2_P2[i] != -1) std::cout << "ERROR 7" << std::endl;
    A2.Free(A2_P1);
    A2.Free(A2_P2);





    // char* a = new char;
    // std::cout << (void*)a << " " << (void*)a + 16 << std::endl;

    // check a;
    // for (size_t i = 0; i < 100; ++i)
    //     std::cout << a.arr[i] << " ";
    // std::cout << std::endl;

    // SmallAllocator a;

    // int *i1 = (int*) a.Alloc(sizeof(int));
    // *i1 = 10;
    // int *i2 = (int*) a.Alloc(2 * sizeof(int));
    // for (size_t i = 0; i < 3; ++i)
    //     *(i2 + i) = i * 11;
    // double* d1 = (double*) a.Alloc(3 * sizeof(double));
    // for (size_t i = 0; i < 3; ++i)
    //     *(d1 + i) = i * 10;

    // std::cout << i1 << " " << *i1 << std::endl;
    // for (int i = 0; i < 2; ++i){
    //     std::cout << &i2[i] << " " << i2[i] << std::endl;
    // }
    // for (size_t i = 0; i < 3; ++i)
    //     std::cout << &d1[i] << " " << d1[i] << std::endl;


    // i2 = (int*) a.ReAlloc(i2, 3 * sizeof(int));
    // i2[2] = 123;
    // for (int i = 0; i < 3; ++i){
    //     std::cout << &i2[i] << " " << i2[i] << std::endl;
    // }



    return 0;
}