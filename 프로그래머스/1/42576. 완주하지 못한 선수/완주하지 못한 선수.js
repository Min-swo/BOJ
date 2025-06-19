function solution(participant, completion) {
    const map = {};
    for(const name of participant) {
        map[name] = (map[name] ?? 0) + 1;
    }
   
    for(const name of completion) {
        map[name]--;
    }
    
    for(const key in map) {
        if(map[key] != 0) {
            return key;
        }
    }
}