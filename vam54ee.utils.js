function gcd (a,b)
{
  if(a === b)
    return a;
  if(a < b)
  return gcd(b,a);
  if(a%b === 0)
    return b;
  return gcd(b,a%b);
}

function compare(a,b)
{
  return a-b;
}

function sort(arr)
{
  arr.sort(compare);
}


function noOfDigits(num)
{
  return num.toString().length;
}
//limit should be greater than 10;
function generateStringSieve(lim)
{
  var primes = '00110101';
  for(var i = 8; i < lim; i++)
    (i%2 === 1)?primes += '1':primes += '0';
  console.log('initialized');
  var finalPrimes = [];
  
  for(var i = 3; i < lim/2;i+=2 )
  {
    for(var j= 3; i*j < lim; j+=2)
    {
      primes[i*j] = '0';
    }
    
    //for(;primes[i] === 0;i+=2);
    //console.log(i);
  }
  console.log("done");
  primes = primes.filter(function(val){return val === '1'});
  console.log("done with final primes with length",primes.length);
  return primes;
}


//limit should be greater than 10;
function generateSieve(lim)
{
  var primes = new Buffer(lim+1);
  var finalPrimes = [];
  primes[2] = 1;
  primes[3] = 1;
  primes[5] = 1;
  primes[7] = 1;
  for(var i = 8; i < lim; i++)
  {
    if(i%2 === 1)
      primes.writeUInt8(1,i);
    else
      primes.writeUInt8(0,i);
  }

  for(var i = 3; i < lim/2; i+=2)
  {
    for(var j= 3; i*j < lim; j+=2)
    {
      primes[i*j] = 0;
    }
    
    //for(;primes[i] === 0;i+=2);
    //console.log(i);
  }
  console.log("done");
  for (var i = 0; i < primes.length;i++)
  {
    if(primes[i] === 1)
      finalPrimes.push(i);
  }
  //primes = primes.filter(function(val){return val === '1'});
  console.log("done with final primes with length",finalPrimes.length);
  return finalPrimes;
}




function binarySearch(value,arr,type)
{
  var start = 0;
  var end = arr.length - 1;
  if(arr[start] === value)
    return start;
  if(arr[end] === value)
    return end;


  for(var i = start, j = end; i < j; )
  {
    var mid = Math.floor((i+j)/2);
    if(arr[mid] === value)
      return mid;
    if(j-i === 1)
    {
      return (type==='left')?i:(type==='right')?j:-1;
    }
    if(arr[mid] > value)
      j = mid;
    else
      i = mid;
  }
  return (type==='left')?i:(type==='right')?j:-1;
}

function reverse(n)
{
  var ret = 0;
  while(n)
  {
    ret = ret*10 + n%10;
    n=Math.floor(n/10);
  }
  return ret;
}

function sumOfDigits(n)
{
  var ret = 0;
  while(n)
  {
    ret += n%10;
    n=Math.floor(n/10);
  }
  return ret;
}

function isPrime(x,arr)
{
  if(x === 2 || x === 3 || x ===5 || x === 7)
    return true;
  if(x % 2 === 0 || (x%10 === 5 && x!== 5))
    return false;
  if(!arr || arr.length < 1)
    arr = generateSieve(Math.sqrt(x));
  if(x > arr[arr.length-1])
  {
    for(var i = 0; i < arr.length; i++)
    {
      if(isInteger(x/arr[i]))
        return false;
    }
    return true;
  }
  else
  {
    return binarySearch(x,arr) > 0? true:false;
  }
}
function isInteger(n)
{
  return n !== Infinity && Math.floor(n)===n;
}

function isPerfectSquare(val)
{
  var per = val%10;
  if(per !== 0 || per !== 4 || per !== 9 || per !== 6 || per !== 1 || per !== 5)
    return false;
  var sqroot = Math.sqrt(val);
  return Math.floor(sqroot) === sqroot;
}

function isHarshad(n)
{
  return Math.floor(n/sumOfDigits(n)) === (n/sumOfDigits(n));
}

function isRightTruncHarshad(n)
{
  while(n)
  {
    if(!isHarshad(n))
      return false;
    n = Math.floor(n/10);
  }
  return true;
}

function Combination(arr,len,cb)
{
  var subset = [];
  function nextElement(arr,index,count)
  {
    if(count === len -1)
    {
      for(var j = index; j < arr.length ;j++)
      {
        subset.push(arr[j]);
        cb(subset.slice());
        subset.pop();
      }
    }
    else
    {
      for(var j = index; j <= arr.length - len+count ;j++)
      {
        subset.push(arr[j]);
        nextElement(arr,j+1,count+1);
        subset.pop();
      }
    }
  }


function start(x)
{
  x?x=  (new Date()).getTime():dt = (new Date()).getTime();
}

function now(x){
  if(Number.isInteger(x))
    return ((new Date()).getTime() - x);
  else
    return (new Date()).getTime() - dt;
}


module.exports = {
  sort:sort,
  noOfDigits:noOfDigits,
  gcd:gcd,
  generateStringSieve:generateStringSieve,
  generateSieve:generateSieve,
  binarySearch:binarySearch,
  reverse:reverse,
  sumOfDigits:sumOfDigits,
  isPrime:isPrime,
  isInteger:isInteger,
  isPerfectSquare:isPerfectSquare,
  isHarshad:isHarshad,
  isRightTruncHarshad:isRightTruncHarshad,
  combination:Combination,
  start:start,
  now:now
}
