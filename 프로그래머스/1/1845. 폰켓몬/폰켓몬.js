function solution(nums) {
    var answer = 0;
    
    const pMap = new Map();
    nums.forEach((num) => pMap.set(num, 1));
    
    answer = pMap.size < nums.length / 2 ? pMap.size : nums.length / 2;
    return answer;
}