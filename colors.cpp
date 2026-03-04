#include <bits/stdc++.h>

using namespace std;

// CYCLE
/*pair<int, int> navigate(int currColor, vector<int> adjColors) {
    int adj = -1; 
    for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 0) adj = i;

    if (adj == -1) return {-1,-1};
    else return {1, adj};
}*/

// STAR
/*pair<int, int> navigate(int currColor, vector<int> adjColors) {
    if (adjColors.size()>1) {
        int adj = -1; 
        for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 0) adj = i;

        if (adj == -1) return {-1,-1};
        else return {0, adj};
    } else return {1, 0};

}*/

//PATH
pair<int, int> navigate(int currColor, vector<int> adjColors) {
    if (adjColors.size()>1) {
        int adj = -1; 
        

        bool on = 0;
        bool tw = 0;

        for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 1) on = 1;
        for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 2) tw = 1;
        
        if (tw) {
            for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] != 2) adj = i;

            if (adj == -1) return {-1,-1};
            return {2, adj};
        } else if (on) {
            if (tw) {
                for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 0) adj = i;
                for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 1) adj = i;

                return {2, adj};
            } else {
                for (int i = 0; i < adjColors.size(); i++) if (adjColors[i] == 0) adj = i;
            }

            if (adj == -1) return {-1,-1};
            return {1, adj};
        } else {
            return {1, 0};
        }
    } else {
        return {2, 0};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


}