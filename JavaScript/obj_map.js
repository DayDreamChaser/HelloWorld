/* 1. Array */
var arr = ['Bart', 'Lisa', 'Adam'];
var names = new Array('Michael', 'Bob', 'Tracy');
// hasOwnProperty/includes join/concat reverse/sort  map/reduce indexOf/slice
var scores = [95, 75, 85];  // toString() push/pop shift/unshift 

for (var key in arr) { 
	console.log("Hello ", arr[key]); //除了索引遍历
}
for (var x of names) { 
	console.log(x); 
}

function gene(num) 
{ 
	var list = []; 
	for (var i = 0; i < num; i++) { 
		list.push(i)； 
	} 
	return list; 
}

/* 它接收一个函数，每次迭代就自动回调该函数 */
arr.forEach(function (element, index, array) {
    // element: 指向当前元素的值
    // index: 指向当前索引
    // array: 指向Array对象本身
    console.log(element + ', index = ' + index);
});


/* 2. object */
var o = {
    name: 'Jack',
    age: 20,
    city: 'Beijing'
};

function iter(obj) 
{ 
	for (var key in obj) { 
		// object中键可以使用for in,遍历的实际上是对象的属性名称
		// array其也是一种object，for in它的索引
		if (obj.hasOwnProperty(key)) { 
			console.log(obj[key]); 
		} 
	} 
}

iter(o);

/* create a obj by keys and values */
function myObj(keys, values) 
{ 
	var obj = {}; 
	for (var i = 0, len = keys.length; i < len; i++) {
		// key in keys must be string
		obj[keys[i]] = values[i]; 
	} 
	return obj; 
}	

var obj = myObj(names, scores);
for (var key in obj) { 
	console.log(key,"-", obj[key]); 
}	


/* 3. Map()数据类型可以充当python中的dict，key可以是非字符串 */
function myMap(keys, values) 
{ 
	var m = new Map(); 
	var len_k = keys.length, len_v = values.length;
	var len = len_k >= len_v ? len_v : len_k; // 短截断
	for (var i = 0; i < len; i++) {
		// key can be anything unchangable
		m.set(keys[i], values[i]); // 多次重复set会覆盖前面的值
	} 
	return m; 
}	

var your_map = myMap(names, scores);
// map对象有clear/delete get/set/has keys/values valueOf/hasOwnProperty方法
your_map.clear(); // 此外还有size属性  entries()等
if (your_map.has("key")) {
	console.log(your_map.get("key"))
}
	
your_map.forEach(function (value, key, map) {
    console.log(key + ' => ' + value);
});	
	
/* 4. Set */
// set的values()等于keys(), 同样有has clear/delete , size
var s2 = new Set([1, 2,3, 43, 2,3,]) 
s2.add(5)

for (var x of s2) { // 遍历集合 s2.keys()或s2.values()一样
    console.log(x);
}

/* iterable可遍历数据类型 Array/Map/Set , 这三种类型都是基于object的*/
/* 使用for ... of  遍历元素*/

// m.keys() m.values()是MapIterator
var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']]);
for (var x of m.keys()) { 
	console.log(x, m.get(x)); 
}

for (var x of m) { // 遍历Map
    console.log(x); // x是形如[1, 'x']的array对象
}

