#ifndef PLAY_UNDOREPO_H
#define PLAY_UNDOREPO_H
#include <vector>
#include "../Domain/Cheltuiala.h"

class Undorepo {
private:
    vector<vector<Cheltuiala>> undo_list;
public:
    void undo_add(vector<Cheltuiala> list);
    void undo_delete();
    vector<Cheltuiala>last_elem();
    Undorepo()=default;

};


#endif //PLAY_UNDOREPO_H
