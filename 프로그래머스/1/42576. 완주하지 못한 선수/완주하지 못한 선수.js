function solution(participant, completion) {
    let answer = '';
    
    const map = {};
    for(const name of participant) {
        map[name] = 0;
    }
    for(const name of participant) {
        map[name]++;
    }
    for(const name of completion) {
        map[name]--;
    }
    
    for(const key in map) {
        if(map[key] != 0) {
            answer = key;
        }
    }
    return answer;
}