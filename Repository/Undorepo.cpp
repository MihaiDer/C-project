#include "Undorepo.h"

void Undorepo::undo_add(vector<Cheltuiala> list) {
    undo_list.push_back(list);
    }

void Undorepo::undo_delete() {
    undo_list.erase(undo_list.end());
}

vector<Cheltuiala> Undorepo::last_elem() {
    return undo_list[undo_list.size()-1];
}

