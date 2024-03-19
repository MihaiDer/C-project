#include "Tests/Tests.h"
#include "Service/Service.h"
#include "Repository/Repo.h"
#include "UI/UI.h"
#include "Repository/Undorepo.h"
int main(){
    Tests tests;
    tests.testAll();
    RepoVector repo;
    Undorepo undo;
    Service service(repo,undo);
    UI ui(service);
    ui.run();
}