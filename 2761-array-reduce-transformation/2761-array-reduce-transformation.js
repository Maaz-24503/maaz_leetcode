/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let ans = init;
    nums.forEach(function(elem){
        ans = fn(ans, elem);
    });
    return ans;
};