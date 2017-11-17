//
//  jigsawGame.cpp
//  AdvProgEX1
//
//  Created by Alexander Shugaley on 03/11/2017.
//  Copyright © 2017 Alexander Shugaley. All rights reserved.
//

#include "jigsawGame.h"
#include <iostream>
#include <string>
using namespace std;








// &&&&&&& supporting functions &&&&&&&&&&
// &&&&&&& supporting functions &&&&&&&&&&
// &&&&&&& supporting functions &&&&&&&&&&


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

// &&&&&&& end supporting functions &&&&&&&&&&
// &&&&&&& end supporting functions &&&&&&&&&&
// &&&&&&& end supporting functions &&&&&&&&&&


bool jigsawGame::readGameFromFile(const char* filename){
    
    
    
    ifstream inf(filename);
    
    if (!inf)
    {
        // Print an error and exit
        cout << "Cannot open output file" << endl;
        return 0;
    }
    string strInput;
    getline(inf, strInput);
    vector<string> spltStr = split(strInput,'=');
    if ((spltStr[0] != "NumElements") || (spltStr.size() > 2)) {
        //first line isn't numElements
        //EROR
        //return false
    }
    spltStr = split(spltStr[1],' ');
    if(!is_number(spltStr[-1])){
        //first line isn't valid
        //EROR
        //return false
    }
    gameSize = std::atoi(spltStr.back().c_str());
    
    
    
    map<int, string> elements;
    while (inf)
    {
        string strInput;
        getline(inf, strInput);
        if (strInput.length() == 0){
            break;
        }
        if(!is_number(split(strInput,' ')[0])){
            //wrong format
            //EROR
            //return false
        }
        int id = atoi(split(strInput,' ')[0].c_str());
        elements.insert(pair<int,string>(id, strInput));
    }

    
    
    
    return insertLines(elements);
}

bool jigsawGame::insertLines( map<int, string> elements){
    bool print = true;
    bool valid = true;
    
    for(int i = 1; i<gameSize; i++){
        map<int,string>::iterator it = elements.find(i);
        if(it == elements.end())
        {
            if(print){
                cout << "Missing puzzle element(s) with the following IDs: " << i;
                print = false;
                valid = false;
            }
            else{
                cout << ", " << i;
            }
        }
    }
    if(!print){
        cout << endl;
    }
    print= true;
    for(map<int,string>::iterator iter = elements.begin(); iter != elements.end(); ++iter)
    {
        int k =  iter->first;
        if (k>gameSize || k < 0){
            if(print){
                cout << "Puzzle of size " << gameSize << " cannot have the following IDs: " << k;
                print = false;
                valid = false;
            }
            else{
                cout << ", " << k ;
            }
        }
    }
    if(!print){
        cout << endl;
    }
    
    for(int i = 1; i<gameSize; i++){
        string line = elements[i];
        vector<string> vline = split(line,' ');
        if(vline.size() != 5){
            cout << "Puzzle ID " << i << " has wrong data: " << line << endl;
            valid = false;
            continue;
        }
    
        for(int j = 1; j < 5; j++){
            if((atoi(vline[j].c_str())!= -1)&&(atoi(vline[j].c_str())!= 0)&&(atoi(vline[j].c_str())!= 1)){
                cout << "Puzzle ID " << i << " has wrong data: " << line << endl;
                valid = false;
                continue;
            }
        }
        jigsawElem* toInsert = new jigsawElem(atoi(vline[0].c_str()),atoi(vline[1].c_str()),atoi(vline[2].c_str()),atoi(vline[3].c_str()),atoi(vline[3].c_str()));
        pieces.push_back(toInsert);
    }
    
    return valid;
}



bool jigsawGame::hasAllCorners(){
    bool tr = false, tl = false , br = false , bl = false;
    
    for(int i = 0; i<gameSize; i++){
        if(pieces[i]->isTopRightCorner()){
            tr = true;
        }
        if(pieces[i]->isTopLeftCorner()){
            tl = true;
        }
        if(pieces[i]->isBotRightCorner()){
            br = true;
        }
        if(pieces[i]->isBotLeftCorner()){
            bl = true;
        }
    }
    return tr && tl && br && bl;
}


bool jigsawGame::hasEnoughEdges(){
    int count = 0;
    for(int i = 0; i<gameSize; i++){
        count += pieces[i]->countStraightEdges();
    }
    return count >= (pieces.size() + 3); //change to sqr root
}

bool jigsawGame::isSumEdgesZero(){
    int sum = 0;
    for(int i = 0; i<gameSize; i++){
        sum += pieces[i]->sumEdges();
    }
    
    return sum == 0;
}


/*
 
 a class represnting a Jigsaw game
 
 should include the following variables: set of pieces (jigsawElem), numOfPieces(int), solutionBoard (double array of jigsawElems[numOfPieces][numOfPieces])
 
 

 
 
 
 */
