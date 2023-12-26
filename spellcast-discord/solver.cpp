#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <unordered_map>
#include <utility>
using namespace std;


string allletters = "qwertyuiopasdfghjklzxcvbnm";
pair<int,int> solutionPaths[3][10];
unordered_map<char,int> LetterValues;
void recsolve(const pair<char,int> (&values)[5][5], unordered_map<string,bool> &k20, pair<int,int> (&pathtaken)[11], pair<string,int> (&solutions)[3], const pair<int,int> &doublepoints, int i, int j, int depth, bool swap){
    //if depth is > 8 then we should NOT run
    if(depth > 8){return;}
    int newDepth = depth + 1;
    //checking the word this makes against what is already in the solutions tab
    int chari = 0;
    string word = "";
    int value = 0;
    bool crossesdob = false;
    //we add our current character to path taken.
    pathtaken[depth-1] = make_pair(i,j);
    map<pair<int,int>,bool> havebeen;
    while(chari != 11 && pathtaken[chari].first != -1)
    {
        int pathtakeword = pathtaken[chari].first;
        int pathtakevalue = pathtaken[chari].second;
        havebeen[make_pair(pathtakeword,pathtakevalue)] = true;
        word += values[pathtakeword][pathtakevalue].first;
        value += values[pathtakeword][pathtakevalue].second;
        if(pathtakevalue == doublepoints.second && pathtakeword == doublepoints.first){crossesdob = true;} //if we cross the double points, double our value
        chari++;
    }
    if(crossesdob){value *= 2;}
    if(depth >= 5){value += 10;}
    //cout << word << endl;
    //cout << solutions[0].first << endl;
    //now we have our word and its value. We check it against the solutions such that if it is more valuable than one of them they get written there instead.
    if(k20.find(word) != k20.end())
    {
        for(int soli = 0; soli < 3; soli++) //We only care about top 3
        {
            if(solutions[soli].second < value)
            {
                // cout << word << endl;
                // cout << value << endl;
                solutions[soli] = make_pair(word,value);
                for(int w = 0; w < 10; w++)
                {
                    solutionPaths[soli][w] = make_pair(pathtaken[w].first,pathtaken[w].second);
                }
                break;
            }
        }
    }
    
    else if(swap)
    {
        //can we make a swap to make a word that k20 stores?
        //its only 25*depth number of swaps and checks.
        for(int swapinteger = 0; swapinteger < depth; swapinteger++)
        {
            char tempstorecharacter = word[swapinteger];
            for(int letters = 0; letters < (int)allletters.length(); letters++)
            {
                if(tempstorecharacter == allletters[letters]){continue;}
                word[swapinteger] = allletters[letters];
                int tempvalue = value;
                tempvalue -= LetterValues[tempstorecharacter] - LetterValues[allletters[letters]]; 
                if(k20.find(word) != k20.end())
                {
                    for(int soli = 0; soli < 3; soli++) //It does have length 10 but we only want top 3.
                    {
                        if(solutions[soli].second < tempvalue)
                        {
                            solutions[soli] = make_pair(word,tempvalue);
                            for(int w = 0; w < 11; w++)
                            {
                                solutionPaths[soli][w] = make_pair(pathtaken[w].first,pathtaken[w].second);
                            }
                            break;
                        }
                    }
                }
            }
            word[swapinteger] = tempstorecharacter;
        }
    }
    
    //NOW We do the recusrion depth searches
    

    if((i+1 != 5) &&  j+1 != 5 &&  havebeen.find(make_pair(i+1,j+1)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i+1, j+1, newDepth,swap);}
    if((i+1 != 5) &&               havebeen.find(make_pair(i+1,j)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i+1, j, newDepth,swap);}
    if((i+1 != 5) &&  j-1 != -1 && havebeen.find(make_pair(i+1,j-1)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i+1, j-1, newDepth,swap);}
    if(               j+1 != 5 &&  havebeen.find(make_pair(i,j+1)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i, j+1, newDepth,swap);}
    if(               j-1 != -1 && havebeen.find(make_pair(i,j-1)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i, j-1, newDepth,swap);}
    if((i-1 != -1) && j+1 != 5 &&  havebeen.find(make_pair(i-1,j+1)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i-1, j+1, newDepth,swap);}
    if((i-1 != -1) &&              havebeen.find(make_pair(i-1,j)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i-1, j, newDepth,swap);}
    if((i-1 != -1) && j-1 != -1 && havebeen.find(make_pair(i-1,j-1)) == havebeen.end()){recsolve(values, k20, pathtaken, solutions, doublepoints, i-1, j-1, newDepth,swap);}
    

    pathtaken[depth-1] = make_pair(-1,-1);
    //clear our path.
    return;
}


int main()
{
    LetterValues['a'] = 1;
    LetterValues['e'] = 1;
    LetterValues['i'] = 1;
    LetterValues['o'] = 1;
    LetterValues['n'] = 2;
    LetterValues['r'] = 2;
    LetterValues['s'] = 2;
    LetterValues['t'] = 2;
    LetterValues['d'] = 3;
    LetterValues['g'] = 3;
    LetterValues['l'] = 3;
    LetterValues['b'] = 4;
    LetterValues['h'] = 4;
    LetterValues['p'] = 4;
    LetterValues['m'] = 4;
    LetterValues['u'] = 4;
    LetterValues['y'] = 4;
    LetterValues['c'] = 5;
    LetterValues['f'] = 5;
    LetterValues['v'] = 5;
    LetterValues['w'] = 5;
    LetterValues['k'] = 6;
    LetterValues['j'] = 7;
    LetterValues['x'] = 7;
    LetterValues['q'] = 8;
    LetterValues['z'] = 8;
    //take in the 20k words and put that into a dictonary
    unordered_map<string,bool> k20;
    pair<char,int> values[5][5];
    //get board state from user and get in 20k words 
    string line;
    ifstream rfile;
    rfile.open("20k.txt");
    if (rfile.is_open()) 
    {
        while (getline(rfile, line)) 
        {
            k20[line] = true;
        }
        rfile.close();
    }

    //

    rfile.open("board.txt");
    int swap = 0;
    pair<int,int> doublepoints = make_pair(-1,-1);
    if (rfile.is_open()) 
    {
        int tempi = 0;
        char tempc = ' ';
        bool doubleletterpoints = false;
        bool tripleletterpoints = false;
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                rfile >> tempc;
                if(tempc == '#'){
                    doublepoints = make_pair(i,j);
                    rfile >> tempc;
                }
                if(tempc == '/'){
                    rfile >> tempc;
                    doubleletterpoints = true;
                }
                if(tempc == '?')
                {
                    rfile >> tempc;
                    tripleletterpoints = true;
                }
                tempi = LetterValues[tempc] + (LetterValues[tempc]*doubleletterpoints) + (LetterValues[tempc]*2*tripleletterpoints);
                doubleletterpoints = false;
                tripleletterpoints = false;
                values[i][j] = make_pair(tempc, tempi);
                cout << values[i][j].first << " ";
                cout << values[i][j].second << " ";
            }
            cout << "\n";
        }
        rfile >> swap;
        rfile.close();
    }



    //NEW ELEMENT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    pair<string,int> solutions[3];

    for(int i = 0; i < 3; i++)
    {
        solutions[i] = make_pair("NULL",-1);
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            pair<int,int> pathtaken[11];
            for(int k = 1; k < 11; k++){pathtaken[k] = make_pair(-1,-1);}
            pathtaken[0] = make_pair(i,j);
            recsolve(values,k20,pathtaken,solutions,doublepoints,i,j,1,swap); 
        }
    }

    cout << solutions[0].first << endl;
    cout << solutions[0].second << endl;
    cout << endl;
    cout << "0,0 on the top left. right inc x down inc y" << endl;
    cout << "X" << " Y" << endl;
    for(int i = 0; i < 8; i++)
    {
        int j = solutionPaths[0][i].second;
        int w = solutionPaths[0][i].first;
        cout << solutionPaths[0][i].second << " " << solutionPaths[0][i].first << " " << values[w][j].first << endl;
    }

    

   return 0;

}