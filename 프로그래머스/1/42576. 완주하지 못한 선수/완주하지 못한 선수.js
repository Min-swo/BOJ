function solution(participant, completion) {
    const m = new Map();
    
    participant.forEach((name) => {
        m.set(name, (m.get(name) ?? 0) + 1)
    })
   
    completion.forEach((name) => {
        m.set(name, m.get(name) - 1)
    })
    
    for(const [key, val] of m) {
        if(val != 0) {
            return key;
        }
    }
}