#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int totalDistance;
        cin >> totalDistance;
        
        vector<pair<int, int>> segments;
        while (true) {
            int start, end;
            cin >> start >> end;
            if (start == 0 && end == 0)
                break;
            segments.push_back(make_pair(start, end));
        }
        
        sort(segments.begin(), segments.end(), [](const pair<int, int>& s1, const pair<int, int>& s2) {
            return s1.first < s2.first;
        });
        
        int currentLeft = 0, rightReach = 0;
        vector<pair<int, int>> chosenSegments;
        
        size_t index = 0;
        while (rightReach < totalDistance && index < segments.size()) {
            int newLeft = currentLeft;
            size_t farthestIndex = 0;
            
            for (; index < segments.size(); ++index) {
                if (segments[index].first > currentLeft)
                    break;
                else if (segments[index].second >= newLeft) {
                    newLeft = segments[index].second;
                    farthestIndex = index;
                }
            }
            
            if (farthestIndex == 0)
                break;
            
            chosenSegments.push_back(segments[farthestIndex]);
            currentLeft = rightReach = newLeft;
        }
        
        if (rightReach >= totalDistance) {
            cout << chosenSegments.size() << endl;
            for (size_t i = 0; i < chosenSegments.size(); ++i)
                cout << chosenSegments[i].first << " " << chosenSegments[i].second << endl;
        } else {
            cout << "0" << endl;
        }
        
        if (testCases)
            cout << endl;
    }
    
    return 0;
}
