#include<iostream>
#include<vector>
#include<cassert>

struct proc_t{
    long count = 0;
    long time = 0;
    friend std::ostream& operator<<(std::ostream& output, proc_t& el){
        output << el.count << " " << el.time;
        return output;
    }
    friend bool operator==(const proc_t& a, const proc_t& b){
        return a.count == b.count && a.time == b.time;
    }
};

class SolveProblem{
public:

    SolveProblem(const std::vector<proc_t>& _procs,
                 const std::vector<long>& _times) : procs(_procs), times(_times){
    }
    SolveProblem(long procC, long timesC) : procs(procC), times(timesC){
        for (long i = 0; i < procC; ++i){
            procs[i].count = i;
        }
        long t;
        for (long i = 0; i < timesC; ++i){
            std::cin >> t;
            times[i] = t;
        }
    }
    
    std::vector<proc_t>& problemSolving(){
        for(long& time : times){
            res.push_back(procs[0]);
            std::cout << procs[0] << std::endl;
            procs[0].time += time;

            siftDown(0);
        }
        return res;
    }
    void siftDown(long ind){
        long newInd = ind;
        long leftC   = 2 * ind + 1;
        if (leftC < procs.size() && (procs[leftC].time < procs[newInd].time  || 
                                    (procs[leftC].time == procs[newInd].time && 
                                     procs[leftC].count < procs[newInd].count))) newInd = leftC;

        long rightC  = 2 * ind + 2;
        if (rightC < procs.size() && (procs[rightC].time < procs[newInd].time  || 
                                     (procs[rightC].time == procs[newInd].time && 
                                     procs[rightC].count < procs[newInd].count))) newInd = rightC;
        
        if (ind != newInd){
            std::swap(procs[newInd], procs[ind]);
            siftDown(newInd);
        }
    }

private:
    
    std::vector<proc_t> procs;
    std::vector<long> times;

    //test result
    std::vector<proc_t> res;

};


void test(){
    int i = 0;
    
    std::cout << "Test #" << ++i << ":" << std::endl;
    SolveProblem pr1({{0, 0}, {1, 0}, {2, 0}},
                     {1, 2, 3, 4, 5});
    std::vector<proc_t> ans1{{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 2}};
    assert(pr1.problemSolving() == ans1 && "Failed!");
    std::cout << "Passed!" << std::endl << std::endl;

    std::cout << "Test #" << ++i << ":" << std::endl;
    SolveProblem pr2({{0, 0}, {1, 0}, {2, 0}},
                     {2, 4, 3, 8, 6, 9, 5, 7});
    std::vector<proc_t> ans2{{0, 0}, {1, 0}, {2, 0}, {0, 2}, {2, 3}, {1, 4}, {2, 9}, {0, 10}};
    assert(pr2.problemSolving() == ans2 && "Failed!");
    std::cout << "Passed!" << std::endl << std::endl;

    std::cout << "Test #" << ++i << ":" << std::endl;
    SolveProblem pr3({{0, 0}, {1, 0}},
                     {0, 0, 1, 0, 0, 0, 2, 1, 2, 3, 0, 0, 0, 2, 1});
    std::vector<proc_t> ans3{{0, 0}, {0, 0}, {0, 0}, {1, 0}, {1, 0}, 
                             {1, 0}, {1, 0}, {0, 1}, {0, 2}, {1, 2}, 
                             {0, 4}, {0, 4}, {0, 4}, {0, 4}, {1, 5}};
    assert(pr3.problemSolving() == ans3 && "Failed!");
    std::cout << "Passed!" << std::endl << std::endl;

    SolveProblem p4({{0, 0}, {1, 0}}, {4, -5, -1, 2, -3});
    std::vector<proc_t> ans4{{0, 0}, {1, 0}, {1, -5}, {1, -6}, {1, -4}};
    assert(p4.problemSolving() == ans4 && "Failed!");

}


int main(){

    // long procCount, timesCount;
    // std::cin >> procCount >> timesCount;

    // SolveProblem pr(procCount, timesCount);
    // std::vector<proc_t> res = pr.problemSolving();
    
    test();
    


    return 0;
}