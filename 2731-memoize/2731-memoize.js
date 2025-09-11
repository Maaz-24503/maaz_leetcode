/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    var dp = {}
    return function(...args) {
        const strArgs = JSON.stringify(args);
        if(strArgs in dp) return dp[strArgs];
        dp[strArgs] = fn(...args);
        return dp[strArgs];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */