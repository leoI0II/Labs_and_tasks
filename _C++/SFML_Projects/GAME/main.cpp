#include"FieldGrid.hpp"
#include"GridView.hpp"

int main(){

    GridCreator creator;
    FieldGrid grid(creator);

    GridView view(grid);

    view.loadPicsFromFile();

    view.draw();
    view.Mode(OutMode::GUI);
    view.draw();

    // FieldGrid grid2(grid);
    // GridView v2(grid2);
    // v2.loadPicsFromFile();
    // v2.draw();

    // FieldGrid grid3;
    // grid3 = grid;
    // GridView v3(grid3);
    // v3.loadPicsFromFile();
    // v3.draw();
    



    return 0;
}