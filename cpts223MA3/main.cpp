#include <map>
#include "generateUsers.hpp"
using namespace std;

map<string, User> buildMapByUserName(vector<User> users) {
    map<string, User> usersMap;

    User vectorUser;

    while (!users.empty()) {
        vectorUser=users.back();
        usersMap.insert(pair<string, User>(vectorUser.userName,vectorUser));
        users.pop_back();
    }

    return usersMap;
}

map<string, User> buildMapByEmail(vector<User> users) {
    map<string, User> usersMap;
    
    User vectorUser;

    while (!users.empty()) {
        vectorUser=users.back();
        usersMap.insert(pair<string, User>(vectorUser.email,vectorUser));
        users.pop_back();
    }

    return usersMap;
}

void printMap(map<string, User> aMap) {
    int i=0;
    for (auto pair : aMap) {
        cout<<"#"<<i<<". Key: "<<pair.first<<", Value: ";
        printAUser(pair.second);
        i++;
    }
}

bool isMapSorted(map<string, User> aMap) {
    bool condition=false;
    if ( aMap.empty() )
        condition = true;
    else {
        condition=true;
        string lastAccessedKey;
        for (map<string,User>::iterator it=aMap.begin();it!=aMap.end();it++) {
            if (it==aMap.begin()) { // for the first element, no check is necessary
                lastAccessedKey=it->first;
            }
            else {
                if(lastAccessedKey>it->first) condition = false;
                lastAccessedKey=it->first;
            }
        }
    }
    return condition;
}

bool testSearchByKey(map<string, User> aMap, string keyToSearch) {
    bool condition = false;
    for (auto pair : aMap) {
        if (pair.first==keyToSearch) condition = true;
    }
    return condition;
}

bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
    bool condition=false;
    if (testSearchByKey(aMap,keyToDelete)) {
        aMap.erase(keyToDelete);
        if (!testSearchByKey(aMap,keyToDelete)) condition = true; // search again to confirm the deletion
    }
    return condition;
}

void printActiveUsers(map<string, User> aMap) {
    int activeThreshold = 800;
    int i=0;
    for (auto pair : aMap) {
        if (pair.second.numPosts>activeThreshold) {
            cout<<"#"<<i<<". Key: "<<pair.first<<endl;
        }
        i++;
    }
}

void printMostPopularCategory(map<string, User> aMap) {
    int popularityCount[7] = {0};
    // by index number
    // 0: Technology
    // 1: Sports
    // 2: Music
    // 3: Food
    // 4: Travel
    // 5: Education
    // 6: Other
    for (auto pair : aMap) {
        if (pair.second.mostViewedCategory=="Technology") popularityCount[0]++;
        else if (pair.second.mostViewedCategory=="Sports") popularityCount[1]++;
        else if (pair.second.mostViewedCategory=="Music") popularityCount[2]++;
        else if (pair.second.mostViewedCategory=="Food") popularityCount[3]++;
        else if (pair.second.mostViewedCategory=="Travel") popularityCount[4]++;
        else if (pair.second.mostViewedCategory=="Education") popularityCount[5]++;
        else popularityCount[6]++;
    }

    int maxPopularity=-1;
    for (int i=0;i<7;i++) {
        if (popularityCount[i]>maxPopularity) maxPopularity=popularityCount[i];
    }
    
    cout<<"Most Popular Categories with "<<maxPopularity<<" users->";

    for (int m=0;m<7;m++) {
        if (popularityCount[m]==maxPopularity) {
            if (m==0) cout<<" Technology";
            else if (m==1) cout<<" Sports";
            else if (m==2) cout<<" Music";
            else if (m==3) cout<<" Food";
            else if (m==4) cout<<" Travel";
            else if (m==5) cout<<" Education";
            else if (m==6) cout<<" Other";
        }
    }

    cout<<endl;
}

int main()
{
    int numUsers = 10;
    
    const string inFile = "../existingData.csv";
    vector<User> users = readCSV(inFile);
    int numInFile = (int)users.size();

    int numToGenerate = numUsers-numInFile;
    vector<User> randomUsers= generateUsers(numToGenerate);

    users.insert(users.end(),randomUsers.begin(),randomUsers.end()); // combining to vectors to get the ultimate list

    cout << "Build map with username as key" << endl;
    map<string, User> mapByUserName = buildMapByUserName(users);
    if ( (int)mapByUserName.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;


    cout << "Print \"mapByUserName\" map:" << endl;
    printMap(mapByUserName);
    cout << endl;


    string keyToSearch = "smith55";
    cout << "Search by key: mapByUserName[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByUserName, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    string keyToDelete = "smith55";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByUserName, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    cout << "Test if map's key is sorted" << endl;
    if ( isMapSorted(mapByUserName) )
        cout << "  Order test passed!" << endl << endl;
    else
        cout << "  Order test failed!" << endl << endl;


    cout << "Print usernames with more than 800 tweets:" << endl;
    printActiveUsers(mapByUserName);
    cout << endl;

    cout << "Print the most popular category" << endl;
    printMostPopularCategory(mapByUserName);
    cout << endl;


    cout << " ============================================================================== " << endl << endl;


    cout << "Build map with username as key" << endl;
    map<string, User> mapByEmail = buildMapByEmail(users);
    if ( (int)mapByEmail.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;
    

    keyToSearch = "kat@gmail.com";
    cout << "Search by key: mapByEmail[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByEmail, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    keyToDelete = "kat@gmail.com";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByEmail, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    return 0;
}