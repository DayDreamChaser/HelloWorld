/* function use */

// js中的函数可以接受任意数量的参数，这里使用arguments关键字来接收参数 
function avg1() {
  var sum = 0;
  for (var i = 0, j = arguments.length; i < j; i++) {
    sum += arguments[i];
  }
  return sum / arguments.length;
}

avg1(2, 3, 4, 5); // 3.5

// 实际经常用arguments来判断参数个数
function area_of_circle(r,pi) {   
   var area = 0;
   if ( arguments.length == 1) {
        const mypi = 3.14;
        area = mypi * (r ** 2);
   } else if ( arguments.length == 2) {
        area = pi * (r ** 2);
   }
    
   return  area;
}

// Rest parameter syntax
function avg(...args) {
  var sum = 0;
  // the variable args holds all the values that were passed into the function
  for (let value of args) {
    sum += value;
  }
  return sum / args.length;
}
avg(2, 3, 4, 5); // 3.5


// deal with array
function avgArray(arr) {
  var sum = 0;
  for (var i = 0, j = arr.length; i < j; i++) {
    sum += arr[i];
  }
  return sum / arr.length;
}

avgArray([2, 3, 4, 5]); // 3.5
// 在js中可以对函数对象使用apply方法，来接受array
avg.apply(null, [2, 3, 4, 5]); // or use-> avg(...[1, 2, 3, 4, 5])

function foo(a, b, ...rest) {
    console.log('a = ' + a); // rest参数会接收一个数组
    console.log('b = ' + b);
    console.log(rest);
}


// recursivly function
var charsInBody = (function counter(elm) {
  if (elm.nodeType == 3) { // TEXT_NODE
    return elm.nodeValue.length;
  }
  var count = 0;
  for (var i = 0, child; child = elm.childNodes[i]; i++) {
    count += counter(child);
  }
  return count;
})(document.body);


/* 变量作用域 */
// 内部函数可访问外部变量。  变量查找会从内部作用域向全局作用域查找
// 独立的两个函数的变量不相关，每一个函数就是一个局部作用域(类似于命名空间)
function foo() {
    var x = 1;  // 函数内的局部变量
    function bar() {
        var y = x + 1; // bar可以访问foo的变量x!
    }
    var z = y + 1; // ReferenceError! foo不可以访问bar的变量y!
}

// 函数本身也是一个变量，这个变量指向函数对象
function parentFunc() {
  var a = 1;
  // “局部全局（local global）
  function nestedFunc() {
    var b = 4; // parentFunc 无法访问 b
    return a + b;
  }
  return nestedFunc(); // 5
}
/* let const可定义(语句块，例如for循环)块级作用域变量
   非函数内部作用域的都是全局作用域， #不使用var会定义全局作用域变量#
   window就是全局对象，this在函数外使用时就只想全局环境对象
*/

// 解构赋值，类似于python的多变量赋值
var arr = [1, 2, 3];
var person = {
    name: '小明',
    age: 20,
    gender: 'male',
    passport: 'G-12345678',
    school: 'No.4 middle school',
    address: {
        city: 'Beijing',
        street: 'No.1 Road',
        zipcode: '100001'
    }
};
var [a, b] = arr;  // array用[],object用{},需要保证嵌套位置一致
var {name, age, address:{ city, street} } = person
// 如果person对象没有single属性，默认赋值为true:
var {gender, single=true} = person;
// 把passport属性赋值给变量id:
let {name, passport:id} = person;

// 使用场景
var x=1, y=2;
[x, y] = [y, x]；

// 如果一个函数接收一个对象作为参数，可以使用解构直接把对象的属性绑定到变量中
function buildDate({year, month, day, hour=0, minute=0, second=0}) {
    return new Date(year + '-' + month + '-' + day + ' ' + hour + ':' + minute + ':' + second);
}
buildDate({ year: 2017, month: 1, day: 1 });
// Sun Jan 01 2017 00:00:00 GMT+0800 (CST)
// 一个闭包，就是一个函数与其被创建时所带有的作用域对象的组合
function makeAdder(a) {
  return function(b) {
    return a + b; // 闭包允许你保存状态
  }
}

/* 每当JS执行一个函数时，都会创建一个作用域对象scope object，用来保存在这个函数中
   创建的局部变量。 每次函数被执行的时候，就会创建一个新的，特定的作用域对象 */
var add5 = makeAdder(5);  
var add20 = makeAdder(20); // 利用闭包将外部函数的参数作为内部的固定参数

/* 当调用makeAdder时，解释器创建了一个作用域对象，它带有一个属性a，这个属性被当作
   参数传入makeAdder函数。然后makeAdder返回一个新创建的函数（暂记为adder）。
   通常，JS的垃圾回收器会在这时回收makeAdder创建的作用域对象（暂记为 b），
   但makeAdder的返回值，新函数adder，拥有一个指向作用域对象b的引用。最终，
   作用域对象 b 不会被垃圾回收器回收，直到没有任何引用指向新函数adder*/
add5(6); 
add20(7);


/* Class in Js*/
//  JavaScript uses functions as classes，自定义对象
function makePerson(first, last) {
    return {
        first: first,
        last: last,
        fullName: function() {
            return this.first + ' ' + this.last;
        },
        fullNameReversed: function() {
            return this.last + ', ' + this.first;
        }
    }
}
s = makePerson("Simon", "Willison");  // funcion return a object
s.fullName(); // Simon Willison
s.fullNameReversed(); // Willison, Simon

// just use this as a funcion object 构造函数
function Person(first, last) {
    this.first = first;
    this.last = last;
    this.fullName = function() {
        return this.first + ' ' + this.last;
    }
    this.fullNameReversed = function() {
        return this.last + ', ' + this.first;
    }
}
// keyword new will create an empty object, the object will call func, and func return this  
var s = new Person("Tim", "Elen"); 


// seperate inner funcion
function personFullName() {
    return this.first + ' ' + this.last;
}
function personFullNameReversed() {
    return this.last + ', ' + this.first;
}
function Person(first, last) {
    this.first = first;
    this.last = last;
    this.fullName = personFullName;
    this.fullNameReversed = personFullNameReversed;
}

// Person.prototype是一个可以被Person的所有实例共享的对象 原型链的一部分
function Person(first, last) {
    this.first = first;
    this.last = last;
}
// 当你试图访问Person没有定义的属性时，解释器会先检查Person.prototype来判断是否存在这样一个属性
Person.prototype.fullName = function() {
    return this.first + ' ' + this.last;
}
// 任何分配给Person.prototype的东西对通过this对象构造的实例都是可用的
Person.prototype.fullNameReversed = function() {
    return this.last + ', ' + this.first;
} 

/* Js允许你在程序中的任何时候修改原型prototype中的一些东西，
也就是说你可以在运行时(runtime)给已存在的对象添加额外的方法 */
s = new Person("Simon", "Willison");
s.firstNameCaps();  // TypeError on line 1: s.firstNameCaps is not a function

// 同样可以给JavaScript的内置函数原型prototype添加东西
Person.prototype.firstNameCaps = function() {
    return this.first.toUpperCase()
}
s.firstNameCaps(); // SIMON

// 原型链的根节点是 Object.prototype
var s = "Simon";
s.reversed(); // TypeError on line 1: s.reversed is not a function

String.prototype.reversed = function() {
    var r = "";
    for (var i = this.length - 1; i >= 0; i--) {
        r += this[i];
    }
    return r;
}
s.reversed(); // nomiS

// apply call
function trivialNew(constructor, ...args) {
    var o = {}; // 创建一个对象
    constructor.apply(o, args);
    return o;
}
// var bill = new Person("William", "Orange");
var bill = trivialNew(Person, "William", "Orange");

// 事件处理 -> 被调用时，将关联的元素变成蓝色
// 当函数被用作事件处理函数时，它的this指向触发事件的元素
function bluify(e){
  console.log(this === e.currentTarget); // 总是 true

  // 当 currentTarget 和 target 是同一个对象时为 true
  console.log(this === e.target);        
  this.style.backgroundColor = '#A5D9F3';
}

// 获取文档中的所有元素的列表
var elements = document.getElementsByTagName('*');

// 将bluify作为元素的点击监听函数，当元素被点击时，就会变成蓝色
for (var i=0 ; i<elements.length ; i++) {
  elements[i].addEventListener('click', bluify, false);
}