#!/usr/bin/python3
# interview problem with ARGO, 9/19/2019

# [[1,3],[2,4],[3,5],[10,15]]
# [[1,5],[-1,-1][-1,-1],[10,15]]
# [[1,3],[2,6],[4,10],[3,15],[20,25]]
# given a list of intervals, merge those having overlap

def mergeInts(ints):
    sort(ints)
    


void mergeIntervals(IntPairVec& intervals) {
    // sort
    std::sort(intervals.begin(), intervals.end());
    auto curr = intervals.begin();
    auto next = curr;
    ++next;
    while(next != intervals.end()) {
        // for (auto it: intervals) cout << it->first << "," << it->second << " "; cout << endl;
        // no overlap: (1,3) (4,5)
        if(curr->second < next->first)
            curr = next;
        // overlap
        else {
            // (1,3) (2,4), half overlap   
            if(curr->second < next->second)
                curr->second = next->second;
            // (1,4) (2,3), hide 
            next->first = next->second = -1;
        }
        ++next;
    }
}

int main() {
    IntPairVec vec{{1,3},{2,4},{3,5},{10,15}};
    for(auto& it: vec) cout << "[" << it.first<<","<<it.second << "] "; cout << endl;
    mergeIntervals(vec);
    for(auto& it: vec) cout << "[" << it.first<<","<<it.second << "] "; cout << endl;
    IntPairVec vec2{{0,5},{1,2},{3,6},{7,11},{10,15}};
    for(auto& it: vec2) cout << "[" << it.first<<","<<it.second << "] "; cout << endl;
    mergeIntervals(vec2);
    for(auto& it: vec2) cout << "[" << it.first<<","<<it.second << "] "; cout << endl;
    IntPairVec vec3{{1,3},{2,6},{4,10},{3,15},{20,25}};
    for(auto& it: vec3) cout << "[" << it.first<<","<<it.second << "] "; cout << endl;
    mergeIntervals(vec3);
    for(auto& it: vec3) cout << "[" << it.first<<","<<it.second << "] "; cout << endl;
}
