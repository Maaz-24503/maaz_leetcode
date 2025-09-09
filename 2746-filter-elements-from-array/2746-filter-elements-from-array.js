/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans = [];
    arr.forEach(function(elem, ind){
        if(fn(arr[ind], ind)) ans.push(arr[ind]);
    });
    return ans;
};