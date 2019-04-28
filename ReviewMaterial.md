# HTML
* Hypertext Markup Language
* meant for research papers
* HTML displays data
  * XML describes data
* [w3schools html tutorial](http://www.w3schools.com/html/default.asp)

minimal html page

```html
<html>

</html>
```

head and body

```html
<html>
  <head>

    <!-- metadata -*

  </head>
  <body>

    <!-- content -*

  </body>
</html>
```

display person data

```html
<!DOCTYPE html>
<html>
  <body>

    <h1>People</h1>

	<table>
	  <tr>
	    <th>name</th>
	    <th>age</th>
	  </tr>
	  <tr>
	    <td>John</td>
	    <td>30</td>
	  </tr>
	  <tr>
	    <td>Amy</td>
	    <td>28</td>
	  </tr>
	</table>

  </body>
</html>
```
# CSS
* style HTML pages

# selectors
* choose **what** to style
* `#` id
* `.` class

# examples

select element with **id of test**

```css
#test {

}
```

select all elements with **class of test**

```css
.test {

}
```

elements that have **both classes**

```css
.one.two {

}
```

paragraphs that have **both classes**

```css
p.one.two {

}
```

**descendants** of #test with class blue

```css
#test .blue {

}
```

**direct descendants** of #test with class blue

```css
#test > .blue {

}
```

# Bootstrap
* Created by Twitter
* CSS library (a giant CSS file)
  * also includes JavaScript and fonts
* mobile first
* responsive


### Using Bootstrap's JavaScript
* Bootstrap's JavaScript file depends on jQuery

### How to use Bootstrap
* can download css, js, font files
* can use CDN

# JavaScript Overview - learn to program in JavaScript

### Background
* Almost completely unrelated to Java
* Loosely typed
* A lot of bad and good parts
* No classes
* Object oriented

### Key Ideas
* Load and go delivery
* Loose typing
* Object as general containers
* Prototypal inheritance
* Lambda
* Linkage through global variables 

### C
* JavaScript is syntactically a C family language
* It differs from C mainly in its type system, which allows functions to be values

# values
* numbers
* strings
* booleans
* null
* undefined
* NaN
* **objects**

### Loosely Typed
* Any of these types can be stored in a variable, or passed as a parameter to any function
* the language is not *untyped*

### numbers
* 64 bit floating point
* floating point numbers are not accurate
```
var x = 0.3 - 0.2; // does not equal 0.1
```

### strings
* 0 or more 16 bit characters
* "" same as ''
* no separate character type
* immutable
* == similar strings are equal
* UCS-2, not UTF-16
* string.length
* String(value) *converts value to a string*

### booleans
* true
* false
* note: values can be *truthy* or *falsey*

### truthy and falsy
* falsy values
  * false
  * null
  * undefined
  * "" *empty string*
  * 0
  * NaN
* all other values are truthy (including all objects)

### null and undefined
* *null* is a value that is not anything
* *undefined* is not even that...

<br/>

* You can assign a value to be null
* *undefined* is the default value for variables, parameters, nonexistent members, etc.
```
var x;        //undefined
var y = null; //null
```

### NaN
* *not a number*

```
var x = 0/0; //NaN
```

# Operators
* arithmetic + - * / %
* comparison == != <> <= >= === !==
* logical && || !
* bitwise & | ^ >> >>> <<
* ternary ?:

### arithmetic
* be careful if you need precision

### comparison
* one note about **equality** operators (==, !=) and **identity** operators (===, !==)

```
var x =  5 ;
var y = "5";

x ==  y //true
x === y //false
```

* equality operators (==, !=) do **type coersion**
* **always use identity operators (===, !==)
### logical
* because values are truthy or falsy, we can use logical operators in neat ways
* the result of a logical operator does not need to be `true` or `false`
* && is called the **guard operator**
  * if first operand is *truthy*, then return **second** operand
  * if first operand is *falsy*,  then return **first** operand
  
```

//long version
if(a) {
  return a.member;
}else {
  return a;
}

//using guard operator
return a && a.member;

```

* || is called the **default operator**
  * if first operand is *truthy*, then return **first** operand
  * if first operand is *falsy*,  then return **second** operand

```

var language = input || "en";

```

* basic examples

```
false || false  //false
true  || false  //true
false || true   //true
true  || true   //true

false && false  //false
true  && false  //false
false && true   //false
true  && true   //true
```

* other examples

```
null || 0     //0
0    || null  //null
1    || 2     //1
2    || 1     //2

null && 0     //null
0    && null  //0
1    && 2     //2
2    && 1     //1
```

* Can you explain why boolean primitives are better to use than Boolean objects?


### bitwise
* need integers to use bitwise operators
* remember numbers in JavaScript are 64 bit floating point numbers
* so when we use bitwise operators, it looks something like:
  * convert 64 bit floating point to 32 bit integer
  * perform bitwise operaton
  * convert 32 bit integer back to 64 bit floating point
* **bad practice** - slow and tough to read

### ternary
* short and sweet

```
var x = true  ? 1 : 0; //1
var y = false ? 1 : 0; //0
```

* bad practice because it is tough to understand

```
//what is x?

var a = false;
var b = true;
var c = true;
var d = false;
var x = a || b ? c && d ? 1 : 2 : 3;
```


# objects
* collection of name/value pairs
  * a **name** can be any string
  * a **value** can be any value *except undefined*
* two ways to create an object
  * object literal `{}` (preferred)
  * constructor (ok, but should not use `new Object()`)

```
var someObject = {};

var john = {
  "name" : "John",
  "age"  : 28
};
```

```
function Person(name, age) {
  this.name = name;
  this.age  = age;
}

var john = new Person("John", 28);
```

* `:` separates names and values
* `,` separates pairs
* as you can see, objects in JavaScript are basically hash tables
* no hash nature is visible (no hash codes or rehash methods)
* members can be accessed with dot notation `object.member` or subscript notation `object["member"]`


### maker functions
* a function that creates and returns an object
* useful if it is difficult or cumbersome to create an object
  * constructors are an alternative solution

```
function makePerson(name, age) {
  var person = {
    "name" : name,
    "age"  : age
  };
  return person;
}

var john = makePerson("John", 28);

```

### object augmentation
* objects are very dynamic

```
var obj = {};

                //obj.x is undefined

obj.x = 7;

               //obj.x is 7

delete obj.x;

              //obj.x is undefined
```




[arrays](arrays.md) and [functions](functions.md) inherit *Object*


# arrays
* array literal `[]`
* `,` separated values

```
var arr = [];

var arr = [10, 20, "John", "Amy", {}];
```


* `[]` is preferred to `new Array()`
* should not use dot notation, instead use *subscript notation*

```
var arr = [10,20,30];

arr[1]; //20
```

* Array inherits from Object
  * array indices are converted to strings and used as names for retreiving values
  * this means arrays and objects are almost exactly the same

```
var example1 = ["John", 20, true];

var example2 = {
  "0" : "John",
  "1" : 20,
  "2" : true
};
```

* main difference between objects and arrays: arrays have *array nature*
  * arrays have a length

### length
* arrays have a length member
* always one larger than the highest integer subscript
  * allows traditional use of for loop

```
var arr = [];
                  //arr.length is 0
arr[9] = "allo";
                  //arr.length is 10

```


### JavaScript arrays in a nutshell
* very efficient for sparse arrays
* not very efficient in most other cases
* one advantage: no need to provide a length or type when creating an array


### should I use objects or arrays?
* use objects when names are arbitrary strings
* use arrays when names are sequential integers

 

# functions
* functions are first-class citizens
  * they can be passed, returned, and stored just like any other value
* Function inherits from Object and can store name/value pairs
* What JavaScript calls function, other language call lambda
  * JavaScript was the first lambda based language to go mainstream
* function statement is shorthand for var statement
  * `function foo(){}` *expands to* `var foo = function(){}`
* no function overloading
  * number of parameters can vary



### scope
* there is a global scope
* functions have scope
* nothing else has scope
  * there is no block scope in JavaScript
  * this means you should define your variables at the beginning of the function

### closure
* this is how we achieve encapsulation
* basically a function in a function

```
function abc() {
  function def() {}
}
```

* inner function retains its *environment*

```
function abc () {
  var str = "hello from outer function";
  function def() {
    console.log(str);
  }
  return def;
}

abc()();
```

* Challenge: write an `add` function such that `add(3,4)` and `add(3)(4)` both return `7`


### method
* a method is a function that belongs to an object

### invocation
* if a function is called with too many arguments, the extra arguments are ignored
* if a function is called with too few arguments, the missing values will be undefined
* no type checking on parameters
* every function gets an `arguments` parameter
* every function gets a `this` parameter, but what it points to depends on the **invocation form**
  * that means that `this` is bound at invocation time

### invocation forms
* function form `someFn(args)`
* method form `someObj.someFn(args)` or `someObj["someFn"](args)`
* constructor form `new someFn(args)`
* apply form `someFn.apply(someObj, [args])`

### function form
* `this` points to the global object
* that is not very useful
* cause of many bugs

### method form
* `this` points to the object which was used during method invocation

```
someObj.someFn(); //inside of someFn, 'this' will point to someObj
```

### constructor form
* when a function is called with the `new` operator, a new object is created and assigned to `this`
* if there is no explicit return statement, then `this` will be returned
* **best practice** is to capitalize functions that are meant to be constructors
  * see below example for why

```
var Person = function(name, age) {
  this.name = name;
  this.age = age;
}

var john = Person("John", 28);
console.log(john);
```


### apply form
* looks weird
* allows you to invoke a method while dynamically setting the object
* `this` points to the object that you pass into the `apply` method


# inheritance
* JavaScript has Prototypal inheritance
  * no classes in JavaScript
* this means that objects inherit directly from other objects
* the parent object is called the `prototype`
* every object has a property called `__proto__` that points to its prototype
* JavaScript has **method overriding**

```
var str = "dog";
console.log(str.__proto__);
```

* example: all strings inherit from `String.prototype`

```
String.prototype.hello = function() {
  console.log("hello from string");
}

var str = "dog";
str.hello();
```

* example: inheritance with custom objects

```
var Person = function() {
  this.hello = function() {
    console.log("hello from person");
  }
}

var Student = function() {
  this.__proto__ = new Person();
}

var john = new Student();
console.log(john.__proto__);
john.hello();
```

# things to watch out for

### semicolon injection
* you need semicolons, however JavaScript will try to help you out by injecting semicolons if it finds a syntax error

```
var someFn = function() {
  return
  {
    name : "John",
    age  : 28
  }
}

var john = someFn();
console.log(john);

```

* the battle of where to put the starting curly brace is over!

### hoisting
* JavaScript *hoists* variable declarations to the top of their respective scopes

```
var someFn = function() {
  str = "ALLO!";
  console.log(str);
  var str;
}

someFn();

```

### implied globals
* if you use a variable and do not declare it, JavaScript assumes it must be a global variable

```
var someFn = function() {
  str = "allo";
  console.log(str);
}

someFn();
console.log(str);
```

# other

### garbage collection
* JavaScript has a garbage collector

### use strict
* put string literal `"use strict"` at the top of a scope to enforce rules

```
"use strict"

var someFn = function() {
  "use strict"

}

```

### typeof

| typeof |    result    |
|:--------------:|:------------:|
|     object     |   "object"   |
|    function    |  "function"  |
|      array     | **"object"** |
|     number     |   "number"   |
|     string     |   "string"   |
|     boolean    |   "boolean"  |
|      null      | **"object"** |
|    undefined   |  "undefined" |


### eval
* can evaluate a string as code
* do not do this

### build-in wrapper types
* JavaScript copied Java wrapper types: Integer, Boolean, etc.
* do not use these

### global
* there is always a global object
* it does not have a name, but it is there
* when JavaScript is running in a browser, the global object does have a name: `window`

### global variables are evil
* use of global namespace must be minimized

### Date
* there is a date object

### RegEx
* we have regular expressions

### threads
* language is neutral on threads
* most implementations do not have threads

### exception handling
* `throw`, `try` and `catch` statements
* 7 built in errors
  * EvalError
  * InternalError
  * RangeError
  * ReferenceError
  * SyntaxError
  * TypeError
  * URIError



# DOM - learn how JavaScript works in a browser
## JavaScript and the DOM

# intro
* JavaScript is widely used in browsers
* while running in the browser, the global object is called `window`
* the Document Object Model (DOM) is a tree of JavaScript objects that is used to render a view
* we can use JavaScript to manipulate the DOM and create dynamic applications

# manipulating the DOM

### finding elements
* `document.getElementById(id)`
* `document.getElementsByTagName(name)`
* `document.getElementsByClassName(name)`

### changing elements
* `element.innerHTML = new html content`
* `element.attribute = new value`
* `element.setAttribute(attribute, value)`
* `element.style.property = new style`

### adding / deleting elements
* `document.createElement(element)`
* `element.removeChild(element)`
* `element.appendChild(element)`
* `element.replaceChild(element)`
* `document.write(text)`


# events

### event categories
* [reference](http://www.w3schools.com/jsref/dom_obj_event.asp)

| categories |            |              |       |
|------------|------------|--------------|-------|
| mouse      | keyboard   | frame/object | form  |
| drag       | clipboard  | print        | media |
| animation  | transition | server-sent  | misc  |
| touch      |            |              |       |

### create event listeners
* three ways to create event listeners
  * `<div onclick="someFn"></div>`
  * `element.onclick = function(){}`
  * `element.addEventListener("click", function(){});`

### the two bad ways
* these are perfect examples of obtrusive / bad JavaScript
* put in HTML section of JSFiddle

```
<div onclick="someFn()">my div</div>

<script>
  var someFn = function(){
    console.log("ALLO!");
  }
</script>
```

```
<div id="my-div">my div</div>

<script>
  var someFn = function(){
    console.log("ALLO!");
  }
  var element = document.getElementById("my-div");
  element.onclick = someFn;
</script>
```

### the one good way
* this is unobtrusive / good JavaScript
* put in HTML section of JSFiddle

```
<div id="my-div">my div</div>

<script>
  var someFn = function(){
    console.log("ALLO!");
  }
  var element = document.getElementById("my-div");
  element.addEventListener("click", someFn);
</script>
```

```
<div id="my-div">my div</div>

<script>
  var element = document.getElementById("my-div");
  element.addEventListener("click", function(){
    console.log("ALLO!");
  });
</script>
```

### addEventListener
* `element.addEventListener(type, handler, useCapture)`
  * **type**       - type of event
  * **handler**    - the function to handle this event
  * **useCapture** - true to use capture *(default is false)*
    * most of the time you do not want capture; instead use bubble


### event handler
* event handlers get passed an `event` parameter
* `event.stopPropagation()` is an important method
  * it will stop calling event handlers
* `event.target` is an important member
  * always points to the lowest element on the tree that was clicked
* while inside the event handler, `this` points to the element that was clicked on
*

```
<div id="my-div">my div</div>

<script>
  var element = document.getElementById("my-div");
  element.addEventListener("click", function(event){
    console.log(event);
  });
</script>
```

### bubble vs capture
* [reference](https://javascript.info/tutorial/bubbling-and-capturing)
* when you click on something, you are actually clicking on many different elements
* bubble and capture determine how you traverse those elements and call their event handlers
* assume I have an event handler for `click` on the elements `body` and `div`

```
<body>
  <div>hello</div>
</body>
```

* **bubble** starts at the bottom of the tree and works its way up
  * first the event handler for the `div` is called, then the event handler for the `body` is called
* **capture** starts at the top of the tree and works its way down
  * first `body` is called, then `div`
* most of the time, **bubble** is what you want
* assume we are using bubble and I want the event handler to run for `div`, but not for `body`
  * this is where `event.stopPropagation()` comes in handy

<br/><br/>
* example - putting it all together
  * put in HTML section of JSFiddle
<br/>

* CSS

```
div {
  text-align:center;
  margin: auto;
}

#three {
  background-color: red;
  width: 100px;
  height: 100px;
}
#two {
  background-color: green;
  width: 80px;
  height: 80px;
}
#one {
  background-color: white;
  width: 60px;
  height: 60px;
}
```

* HTML

```
<div id='three'>3
  <div id="two">2
    <div id="one">1</div>
  </div>
</div>
```

* JavaScript

```
var myEventHandler = function(event){
  alert("target: " + event.target.id + " - this: " + this.id);
}

var divs = document.getElementsByTagName("div");

for(var i = 0; i < divs.length; i++){
  divs[i].addEventListener("click", myEventHandler);
}
```

* try adding a third parameter of `true` to the `addEventListener` method
  * how does the output change?

# ajax
* Asynchronous JavaScript and XML
* ignore the XML part of that word, JSON is frequently used
* the ability to send requests from JavaScript **asynchronously**
  * this means we can send a request and forget about it
  * when we get the response, then we will handle it
  * do not have to wait in the meantime (think about when you text or email someone... do you have to wait for a response?)
* AJAX has four steps
  1. create object
  +  define onreadystatechange function
  +  open request *(can configure HTTP method and url)*
  +  send request *(can send data in request body)*
* naive example - do not run

```
var xhr = new XMLHttpRequest();

xhr.onreadystatechange = function(){
  if(this.readyState == 4 && this.status == 200){
    console.log("response received!");
    console.log(this.responseText);
  }
}

xhr.open("GET", "someUrl", true);

xhr.send();

```

### creating the object
* most of the time, the object we need is XMLHttpRequest
* older versions of IE had a different object from everyone else

```
var xhr;
if(XMLHttpRequest) {
  xhr = new XMLHttpRequest();
}else {
  xhr = new ActiveXObject("Microsoft.XMLHTTP"); //IE6 and older
}
```

### onreadystatechange
* most notably, XMLHttpRequest has members called `readystate`, `status` and `responseText`
* the `onreadystatechange` function is called whenever the `readystate` member changes

| readystate |                 meaning                |
|:----------:|:--------------------------------------:|
|      0     | request not initialized                |
|      1     | server connection established          |
|      2     | request received                       |
|      3     | processing request                     |
|      4     | request finished and response is ready |

* obviously we care the most when `readystate` is 4
* `status` will be one of the HTTP status codes
  * this is a naive example because we only handle when the status code is `200`
* `responseText` is the response body represented as a string

### open request
* `open(method, url, async)`
  * **method** - the HTTP method
  * **url**    - the url to send the request to
  * **async**  - true or false *(default is true)*


### send request
* `send(string)`
* sends the request
* **string** is optional
  * use to send data in the request body
  * cannot use with GET requests

### example
* open a browser and enter following url: `https://pokeapi.co/api/v2/pokemon/pikachu/`
* we are going to get that data using JavaScript
* you can enter the following into JSFiddle *(JavaScript section)*

```
var xhr = new XMLHttpRequest();

xhr.onreadystatechange = function(){
  if(this.readyState == 4 && this.status == 200){
    var pikachu = JSON.parse(this.responseText);
    console.log(pikachu.name);
    console.log(pikachu);
  }
}

xhr.open("GET", "https://pokeapi.co/api/v2/pokemon/pikachu/");

xhr.send();
```

# json
* [reference](http://www.json.org/)
* JavaScript Object Notation
* created by Douglas Crockford
* a way to represent data in a language agnostic way
  * similar to xml, yaml, csv
* JSON was inspired by the way JavaScript represents objects
  * JSON and JavaScript objects are not the same thing
* JSON restrictions
  * 'undefined'
  * functions
  * numbers must be base 10
  * names must have quotes

### JSON document
* object `{key : value, key : value}`

### Keys
* Must be strings

### Values
* string
* number
* true / false
* array `[value, value, value]`
* object `{key : value, key : value}`
* null

```
{}
```

```
{
  "name" : "John"
}
```

```
{
  "colors": ["blue", "green", 42]
}
```

```
{
  "make": "Jeep",
  "model": "Wrangler",
  "year": 2004
}
```


```
{
  "name" : "John",
  "car": {
    "make": "Jeep",
    "model": "Wrangler",
    "year": 2004
  }
}
```

# jQuery
* JavaScript library
* simplifies and adds additional functionality to JS
* basic syntax is `$(selector).action()`
  * `$` defines/assesses jQuery
  * the action is what is to be performed on the elements
* only a single global object
  * `$` and `jQuery` point to the same global object
* the `jQuery` object is actually a function
  * when you invoke the function, it traverses the DOM
  * the `jQuery` function has methods like `ajax`
* jQuery uses CSS selectors
  * Allow you to select and manipulate HTML elements
  * `$([element])`
  * `$(.[class])`
  * `$(#[id])`
* The Document Ready Event
  ```
  $(document).ready(function(){ 
		//jQuery method here
  });
  ```
  * This exists to prevent any jQuery code from running before the document is finished loading
	* Ex of actions that can fail if methods are run before doc is fully loaded - trying to hide an element that hasn’t been created yet

* the `ajax` method takes in an object
  * this object has members to configure the request
  * no more worrying about what browser you are in
  * this is one step... remember with plain JavaScript it was four steps

```
$.ajax({
  method   : "get",
  url      : "someUrl",
  success  : function(){},
  error    : function(){},
  complete : function(){}
});
```

# SQL
	Order of Operations
	FROM
	WHERE
	GROUP BY
	HAVING
	SELECT
	ORDER BY
## Sublanguages
**DCL** Data Control Language, setting user permissions (GRANT, REVOKE)

**DDL** Data Definition Language, working with database structure (CREATE, ALTER, TRUNCATE, DROP) EX:
```sql
CREATE TABLE (Schema)[TableName]
(Column definitions (Constraints))


ALTER TABLE [TableName]
ADD (Column) [Column definition]
ADD (Constraint clause)
DROP [column] [cascade]
DROP Constraint
ALTER COLUMN [definition]
```

**DML** Data Manipulation Language, working with the rows of data itself (INSERT, UPDATE, DELETE) EX:
```sql
INSERT INTO [TableName] [columns]
VALUES (data input)
SELECT (drop entire result set into table)
```

**DQL** Data Query Language, retrieving rows of data (SELECT). EX:
```sql
SELECT [columnList]
FROM [tableList]
WHERE [conditionList]
GROUP BY [columnList] // aggregate functions
HAVING [condition]  // aggregate functions
ORDER BY [columnList]
```

**TCL** Transaction Control Language, managing transactions (COMMIT, ROLLBACK, SAVEPOINT)
```sql
SAVEPOINT this_point;
INSERT ...
INSERT ...
INSERT ... --Error here
ROLLBACK TO this_point; --Undo last 3 inserts
INSERT ...
COMMIT; --Only last insert will commit
```

**Sequences** Generate numeric sequence, mostl for creating/managing primary keys.

**Views** Virtual table that displays the results of a SELECT statement, lets you reuse and store complex queries

**Indexes** Physical ordering of a column or group of columns, having unique indexes

**Alias** The `AS` or `IS` keyword allows you to set a Table name or column name as a short variable.

**Aggregate Functions** (AVG, MIN, MAX, SUM, COUNT) perform an action on an entire column

**Scalar functions** (LOWER, UPPER) operate on individual entries

## Joins
Combine rows from two tables based on some logical relationship between them (columns)
### Types
1. Inner Join, selects records with matching values from TableA and TableB
1. Left (Outer) Join, TableA primary, selects all records from A with matching values from B (non-matching values included as null)
1. Right (Outer) Join, TableB is primary, opposte of Left Join.
1. Cross Join, Cartesian join of two tables, if TableA has 5 rows, and TableB has 3 rows, the cross join will have 15 rows
1. Subquery is a query nested in the WHERE clause of a SELECT statement, in orde3r to further restrict the data returned. There are correlated and non-correlated. Correlated subqueries depend on the outer query to exist, meaning they cannot execute independently.

## Unions
1. UNION returns distinct rows present in either return set
1. UNION ALL returns all rows in both sets (including duplicates)
1. INTERSECT returns distinct rows present in both sets
1. MINUS returns all rows present in first set but not in second

# RDBMS
Relational Database Management System, relational referring to relational data (i.e. tables).

**Schema** 
	Like packages/namespaces, groupings of tables expressing some database logical structure.

**SQL implementations** 
	There is PostgreSQL is an Enterprise Database like Oracle, SQL Server, but there are others like MySQL/MariaSQL as well as non relational SQL databases (NoSQL).

**Candidate Key** 
	A column that can uniquely identify a row (or entry) and thus is a potential candidate for a primary key.

**Composite Key** 
	A primary key consisting of multiple columns.

**Primary Key** 
	Unique (in that table), non-null candidate key.

**Foreign Key** 
	A key that points to another primary key of a row (either in another table, or the same).

**Multiplicity** 
	Refers to the relationship between linked tables. One-to-One (University, President), One-to-Many (University, Students), Many-to-Many (Students, Teachers). In 1:1, FKs will be within same table. 1:many, FKs will be in the other table. many:many, FKs will be in a junction/transition/join/lookup table.

**Referential Integrity** 
	Enforcing data relationships, changes reflected between foreign keys. No orphans, all child rows must have their parent rows deleted as well.

**Domain Integrity** 
	Column data is restricted to allowed range of allowed type.

**ERD** 
	Entity-Relational Diagram

**Normalization** 
	Efficiency and reduce redundancy
	   - this is done in normal forms we typically go up to third normal form (3NF)
   - "the key, the whole key, and nothing but the key"
   - 1NF - every table must have PK
            atomic values for columns (broken down into small units)
   - 2NF - every column in table is dependent on entire PK (no partial dependencies)
          also must be in 1NF
   - 3NF - every column must depend directly on PK, not on another column that does (no transitive dependencies)
          also must be in 2NF

# jdbc
* Java Database Connectivity
* How Java can talk to a database
* `java.sql`
* `SQLException`

# Interfaces
* `Connection`
* `Statement`, `PreparedStatement`, `CallableStatement`
* `ResultSet`

# Statement
* never use

# PreparedStatement
* precompiled
* faster
* safe against sql injection

# CallableStatement
* call procedures

# ResultSet
* result of `select` statement

# PL/SQL
* Procedural Language / SQL
* created by Oracle
* SQL is not turing complete
  * basically it is not a *full* language
* features
  * variables
  * functions
  * exception handling
  * looping / conditional constructs

# example table

```
create table flash_card(
  fc_id integer primary key,
  fc_question varchar2(2000),
  fc_answer varchar2(2000)
);
```

# Sequences
* pattern

```
create sequence fc_id_sequence
  start with 1
  increment by 1;
```

# Triggers
* block of code that is automatically executed when events happen

```
CREATE OR REPLACE TRIGGER fc_insert_trigger
BEFORE INSERT ON flash_card
FOR EACH ROW --required if you want to see/manipulate the row's data
BEGIN
      SELECT fc_id_sequence.nextval INTO :new.fc_id FROM DUAL;
      --DUAL is a dummy table, typically used when you don't require a table
      --but you still need the syntax of a sql statement to be correct
END;
/
```

let's test it out

```
insert into flash_card(fc_question, fc_answer) values('what is java?', 'awesome');
insert into flash_card(fc_question, fc_answer) values('who is Douglas Crockford?', 'the man');
insert into flash_card(fc_question, fc_answer) values('who is Moby Dock?', 'Docker''s mascot');
```

# Functions
* block of code that you can execute
  * can call from `select`, `insert`,
* 0 or many parameters
* must return 1 value

function

```
CREATE OR REPLACE FUNCTION get_max_id
RETURN NUMBER
IS
  max_id NUMBER;
BEGIN

  SELECT MAX(fc_id) INTO max_id FROM flash_card;
  RETURN max_id;

END;
/
```

invoke function

```
DECLARE
  dog NUMBER;
BEGIN

  dog := get_max_id();

  DBMS_OUTPUT.PUT_LINE('max id is: ' || dog);

END;
/
```

# Stored Procedure
* block of code that you can execute
* 0 or many IN parameters
* 0 or many OUT parameters

stored procedure

```
CREATE OR REPLACE PROCEDURE insert_flash_card(new_question IN VARCHAR2, new_answer IN flash_card.fc_answer%TYPE)
IS
BEGIN
  INSERT INTO flash_card(fc_question, fc_answer) VALUES(new_question, new_answer);
  COMMIT;
END;
/
```

invoke stored procedure

```
BEGIN
  insert_flash_card('what is the answer to life, the universe, and everything', '42');
END;
/
```

# transaction (tx) theory

# ACID
* **Atomic** - all or nothing
* **Consistency** - bring the database from one valid state to another
* **Isolation** - concurrent tx run the same as sequential tx
* **Durability** - once a tx is committed, it will remain so

# Tx Isolation Levels

in order from least restrictive to most restrictive

* read uncommitted - dirty reads, non-repeatable reads, and phantom reads can occur.
* read committed - non-repeatable reads and phantom reads can occur.
* repeatable read - phantom reads can occur.
* serializable - None can occur

# When bad things happen
* dirty read
* non-repeatable read
* phantom read

# Java
Java is an object-oriented programming language and a platform developed by Sun Microsystems (eaten by Oracle). Using the principle of **WORA** (Write Once, Run Anywhere), a Java application can be compiled and executed on any platform supported by Java. Flexible, popular, and well-supported, Java has helps developers write scalable client-server web applications, desktop and mobile applications, and frameworks and libraries.

## Features
- **Platform independence**: The compiler converts source code to bytecode, then the JVM executes that bytecode. While each operating system has their own JVM implementation, so every JVM can execute bytecode regardless of origin of said code.

- **Clear, verbose syntax** Java has C-like syntax like C++ and C#, many syntax elements of the language are readable and widely used in programming. The Java API (Application Programming Interface) is also written using verbose, descriptive naming conventions making it simple to parse large code bases.

- **Multi-paradigm** While Java is object-oriented, it supports multiple paradigms such as imperative, generic, concurrent, and functional.

- **Garbage collection** The JVM performs automatic memory deallocation of unused objects at runtime. Programs are written without the need for complex memory management.

- **Multithreading** Java supports multithreading at both language and the standard library levels. It allows concurrent and parallel execution of several parts of a Java program.

- **Object-Oriented Programming** Although Java accommodates several paradigms, OOP is the foundation for most applications. In OOP, a program is organized into objects encapsulating related fields (representing its *state*) and methods (usually to control that state or perform related functions). When defining objects, Java reserves the keyword *class* (not to be confused with the *.class* file extension) which serves as their blueprint. An object in Java represents an instance in memory of a class, and also every class implicitly inherits from the *Object* superclass which provides useful convenience methods such as *equals()* and *toString()*. Java popularized several 'Pillars' of OOP design theory. While the numbers vary between OOP languages, Java focuses on four:

    - *Abstraction* - By hiding implementation details, we reduce complexity, and increase efficiency.

    - *Encapsulation* - Access to the data and code is tightly controlled by an interface. Also known as data hiding, because the object has sole responsibility for its fields, and no outside object or function should interfere.

    - *Inheritance* - Code reuse is an important principle of programming (DRY - Don't Repeat Yourself), and new classes can reuse code from existing ones. This establishes a superclass-subclass (or parent-child) relationship where the derived classes inherit (and sometimes change) fields and methods from its parent.

    - *Polymorphism* - With inheritance, an object of a derived class can be referenced as instances of its parent class. This provides flexibility when invoking inherited methods with varying implementations in derived classes.

## Variables
A value is stored and identified in memory by a variable. Variables have a name that makes it possible to access the value, and a type that defines what sort of value it stores.
```java
int variableName = 64;
String txtVar = "Hello World";
```

## Primitive data types
Java handles two kinds of datatypes: primitives and references. Primitives are variables that store simple values. There are eight in Java.
- Integer types: **byte** (8bit), **short** (16bit), **int** (32bit), **long** (64bit)  
- Floating-point types: **float** (32bit) **double** (64bit)  
- Logical types: **boolean** (T/F)  
- Character type: **char** (16bit)

### Casting
* convert one data type to another
* must cast if there might be a problem

### Autoboxing
* Java 1.5 feature that made it easier to move between primitives and wrapper classess
* **boxing** is primitive to object
* **unboxing** is object to primitive

### Default values

| primitive |           default value           |
|:---------:|:---------------------------------:|
|    byte   |                 0                 |
|   short   |                 0                 |
|    int    |                 0                 |
|    long   |                 0L                |
|   float   |                0.0f               |
|   double  |                0.0d               |
|  boolean  |               false               |
|    char   | ‘\u0000’ //unicode null character |
* default value for all objects is `null`

## Reference types
Reference types store the memory address location of more complex data types in the heap. Reference types include:
- Classes * abstract methods and concrete methods
- Interfaces *  abstract methods
- Enums
- Arrays
- Annotation

## Naming variables
- Case sensitivity
- Can only use letters, numbers, and *$* or *_* characters
- Cannot begin with a number
- Cannot be a reserved Java keyword

## Scopes of a variable
A variable's reference will only exist within the context of its declared scope, which is based on the location of its declaration.

- **Static** or class scoped variables are visible to all instances of a related class.
- **Instance** or object scoped variables are visible to only that object instance.
- **Local** or method scoped variables are visible only within a method.
- **Block** or loop scoped variables are visible only within a block statement.

Be aware of *shadowing*: when two variables in different scopes share names.

## Methods
Methods accept a list of arguments known as *parameters* and return some value. They are used to implement repeatable, consistent actions on variable input, much like math functions.
```java
public int myMethod(int a, int b);
public int myMethod(int a);
```

## Constructors
Classes not only define object fields and methods, but how it should be instantiated through special methods called constructors. Constructors must have no return type and share the same name as its class. Java will automatically give you a *noargs* constructor. However, if you define any constructor, you will lose the automatically given constructor.

While a constructor may be *private*, used for singletons, it may not be *final*, *static*, or *abstract*.

# Access modifiers
* private
* *default*
* protected
* public

|           | within same class | within same package | subclasses | everyone |
|:---------:|:-----------------:|:-------------------:|:----------:|:--------:|
|  private  |        YES        |          no         |     no     |    no    |
|  default  |        YES        |         YES         |     no     |    no    |
| protected |        YES        |         YES         |     YES    |    no    |
|   public  |        YES        |         YES         |     YES    |    YES   |

Classes should only be public or default. There are no cascading access levels, and unspecified fields will be default. Subclasses can only change inherited fields to be less restrictive.

## Classes
* Classes are complex data types
* Classes are blueprints for objects
* Describe the state and behavior of a data type
* Example: A Person has a name and a age.

```
class Person {
  String name;
  int age;
}
```

## Objects

* An object is an instance of a class
* John is a Person instance
* use the `new` keyword to create an object
* useful methods
  * toString
  * equals
  * hashCode

### toString
* method that gets called when you *print* an object
* by default, prints memory address
* should override

### equals
* returns `boolean`
* test equality between objects
* for objects, `==` tests if memory addresses are the same
* by default, `equals` uses memory address
* should override

### hashCode
* returns `int`
* by default, returns memory address
* must override if you override `equals`
* used in *hash based* collections: `HashSet`, `HashMap`
* contract of an object - Joshua Bloch
  * `hashCode` should return the same int over and over, as long as I do not change anything in the equals method
  * objects that are *equal* must have the same hash code
  * objects that are not *equal* may have the same hash code
* Usually people mess up on the 2nd bullet point
* In the Hash Table data structure, we call the 3rd bullet point a **hash collision**

```
Person john = new Person();
```

## More on classes
* There are 4 types of classes
  * We will only talk about **outer** classes

in file `Person.java`

```
public class Person {

  //variables
  String name;
  int age;

  //methods  
  void methodOne() {

  }

  void methodTwo() {

  }
}
```

create Person object

```
Person john = new Person();
```

access instance variables

```
john.name = "John";
```

invoke instance methods

```
john.methodOne();
```

each instance gets its own set of instance variables

```
Person john = new Person();
Person amy  = new Person();

john.name = "John";
amy.name = "Amy";

System.out.println(john.name); //prints John
```

## Methods
* a block of code that I can invoke / call
* black box
  * give it *input* and get back *output*
  * I do not know what happened inside
* **Method Signature**
  * return type
  * method name
  * parameters

examples
```
void someMethod() {

}

someMethod(); //invoke method
```

```
int someMethod() {
  return 5;
}

int a = someMethod(); //invoke method. a is 5
```  

```
int add(int x, int y) {
  return x + y;
}

int a = add(3, 4); //invoke method. a is 7
```

notice the **arguments** do not have to have the same names as the **parameters**
* where are the **arguments**?
* where are the **parameters**?

```
int add(int x, int y) {
  return x + y;
}

int first  = 3;
int second = 4;

int a = add(first, second); //invoke method. a is 7
```

## Constructors
* special method
* does not have a return type
  * the return type is *implicitly* an object
* must have the same name as the class
  * case matters
* Constructors are invoked when we use the `new` keyword

example of no arg constructor

```
public class Person {

  public Person() {

  }

}
```

more verbose example
* `this` points to this object
* it essentially gives you a reference to yourself

```
public class Person {

  String name;
  int age;

  public Person(String name, int age) {
    this.name = name;
    this.age = age;
  }  
}
```

we can invoke that constructor as follows

```
Person john = new Person("John", 28);
```

we can also overload constructors
* **method overloading** is when you define two or more methods with the same name in the same class
  * we cannot be ambiguous, so either the number of parameters or the parameter data types must be different
* you can overload normal methods too  

```
public class Person {

  String name;
  int age;

  public Person(String name) {
    this.name = name;
  }

  public Person(String name, int age) {
    this.name = name;
    this.age = age;
  }  
}
```

invoke the first constructor

```
Person john = new Person("John");
```

invoke the second constructor

```
Person john = new Person("John", 28);
```

How were we able to create instances without defining a constructor?
* When Java sees there are no constructors in a class, Java will insert a **default constructor**
* the **default constructor** is a no arg constructor: `public Person(){}`

## Pass by value
* Learn [stack vs heap](stack-vs-heap.md) first
* Other languages have concepts of *pass by value* and *pass by reference*
* Java does not allow us access to pointers
* Java is only *pass by value*

what is the output?

```
public static void main(String[] args) {
  int x = 1;
  someMethod(x);
  System.out.println(x);
}

static void someMethod(int a) {
  a = 100;
}
```

what is the output?
* tricky

```
public static void main(String[] args) {
  int x = 1;
  someMethod(x);
  System.out.println(x);
}

static int someMethod(int a) {
  a = 100;
  return a;
}
```

what is the output?

```
public static void main(String[] args) {
  int x = 1;
  x = someMethod(x);
  System.out.println(x);
}

static int someMethod(int a) {
  a = 100;
  return a;
}
```

that's pretty much the same behavior in other languages
* what about objects?

what is the output?

```
public static void main(String[] args) {
  Person john = new Person("John", 28);
  someMethod(john);
  System.out.println(john);
}

static void someMethod(Person someone) {
  someone.age = 100;
}
```

ok... how is that not **pass by reference**?
* technically we are passing the value of the memory address of john

what is the output?

```
public static void main(String[] args) {
  Person john = new Person("John", 28);
  someMethod(john);
  System.out.println(john);
}

static void someMethod(Person someone) {
  someone = new Person("Amy", 27);
}
```

## Static
* something that belongs to the class
  * you can have static **methods** and **variables**
  * you can have static classes, but that's a discussion for another day
* you do not need an instance to use it

class with static members

```
class MyClass {
  static int x;

  static void someMethod() {
    System.out.println("allo");
  }
}
```

accessing those static members

```
MyClass.x = 1;
MyClass.someMethod();
```

Each instance gets its own set of instance variables.
There is only ever one set of static variables.
* static variables are allocated memory at *class loading time* i.e. right before the code runs

```
class Test {
  int x;
  static int y;
}
```

# Plain old java object *(POJO)*
* class with no conventions

# Java Bean
* follows certain conventions
  * should have public *getters* and *setters*
  * should have public no arg constructor

# Arrays
* a collection of elements of the same type
* must specify **type** and **size**
  * arrays are allocated a block of memory on the heap
  * arrays have a fixed size
* arrays arrays have a `length` member * int[] myArray = new int[5]; myArray.length //returns 5
```java
// One-Dimensional Arrays
int[] instancedArray = new int[3];
int[] literalArray = {1, 2, 3};

// Two-Dimensional Arrays
int[][] instanced2DArray = new int[3][4];
int[][] literal2DArray = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
```

## Iteration
Java for loops can iterate through arrays like most other languages:
```java
// One-Dimensional Arrays
for (int i = 0; i < arrayOne.length; i++) {
    System.out.print(arrayOne[i]);
}

// Two-Dimensional Arrays
for (int i = 0; i < 2DArrayOne.length; i++) {
    for (int j  =0; j < 2DArrayOne[i].length; j++) {
        System.out.print(2DArrayOne[i][j]);
    }
}

// Foreach loops
for (int i : arrayOne) {
    System.out.print(i);
}
```

## Manipulation
The `java.util.Arrays` class provides various methods for manipulating arrays.

```java
int[] messyArray = {234, 5346, 3, 64};
Arrays.sort(messyArray);
System.out.println(Arrays.toString(messyArray));
```

## Varargs
Varargs is a special parameter that can accept multiple arguments of the same type into a dynamically constructed array, and denoted by an ellipsis (...) instead of brackets. A varargs parameter must be the last or only parameter in a method signature. 
```java
varArgMethod("m", 1, 2, 5, 35, 346, 345, 4634);

...

public static void varArgDemo(String m, int... intArgs) {
    for (int i : intArgs) {
        System.out.print(i);
    }
}
```
# Programming and Compiling
Most Java applications only require the **JRE** (Java Runtime Environment). But to write and compile you need the **JDK** (Java Development Kit). While the JRE provides Java's standard libraries and exceptions as well as a JVM, the JDK provides all the above as well as *javac*, the compiler. Java source code is written in text files labeled with *.java* extension. It is then compiled into bytecode in *.class* files by *javac*. Then the bytecode is executed by the JVM, which translates the Java commands into low-level instructions to the operating system.

Since Java 6, all Java programs not run inside a container (such as a Servlet Web Container) start and end with the main method. The class containing the main method can have any name, but the method itself should always be named *main*

```java
class Example {
    public static void main(String[] args) {
        System.out.println("Num args:" + args.length);
    }
}
```

- *public* is a Java access modifier keyword that means the `main` method can be accessed from any method during the program's execution.
- *static* is a Java keyword that means the method can be invoked without creating an instance of the class that contains it, making it a global method.
- *void* is a Java return type keyword that means the method doesn't return any values of any data type.
- *args* is a Java variable of type String array which means the method can take command line arguments as an array of Strings

We can compile this code into a *.class* file of the same name:
>javac Example.java

And to run the resulting `Example.class` file:
>java Example

The `java` and `javac` commands require the full directory path or class path to any source code or binary file respectively. If you have a package `com.demo` in the first line of Example, then you would nest the java file into a `com/demo/` directory and then run:
>javac com/demo/Example.java 

>java com.demo.Example

From here we can add packages and imports, expanding the application into a set of interacting objects. By default, the *javac* compiler implicitly imports several base packages from the standard library.

# Maven 
Build automation and dependency management tool. Once installed, use with the `mvn` command. Allows for a project to be IDE agnostic. See the official Maven project for documentation: http://maven.apache.org/index.html as well as the mvn repository to find available libraries: https://mvnrepository.com/

The minimum `pom.xml` example:
```xml
<project>
  <modelVersion>4.0.0</modelVersion>
  <groupId>YourDomainName</groupId>
  <artifactId>YourProjectName</artifactId>
  <version>0.1.0</version>
</project>
```

# JUnit
* unit test our code
* a unit test focuses on a really small part of the codebase: a single method
* tests should not care what order they are run in

# Test Driven Development (TDD)
* write unit tests first
* watch them fail
* write code to satisfy tests

# JUnit Annotations
* `@Ignore` - ignore a unit test
* `@BeforeClass` – Run once before any of the test methods in the class, public static void
* `@AfterClass` – Run once after all the tests in the class have been run, public static void
* `@Before` – Run before @Test, public void
* `@After` – Run after @Test, public void
* `@Test` – This is the test method to run, public void

# Design Patterns: Dependency Injection
Some classes require another class, a dependency. While the dependency can be defined in the dependant class's own constructor, this introduces several problems such as tightly coupling the two classes and introducing difficulties during unit testing. To solve this, we can inject the dependency as an argument into the dependant class's constructor or setter.

```java
public class Order {
    private Customer customer;

    // Constructor Injection
    public Order(Customer customer) {
        this.customer = customer;
    }

    // Setter Injection
    public setCustomer(Customer customer) {
        this.customer = customer;
    }
}
```

## Testing Benefits
By injecting dependencies, we can more easily test this class without having to also test the dependency which can be independantly tested, if necessary. The injection pattern means that a mocked dependency can be injected in the original dependency's place.

```java
public class MockCustomer extends Customer {
    // Stub methods overriding the super class methods
}
```

```java
public class OrderTest {
    @Test
    public void testMock() {
        Order order = new Order(new MockCustomer);
    }
}
```

# JDBC API
Java Database Connectivity (JDBC) is an API for connecting to a RDBMS such as Oracle, PostgreSQL, or MySQL. As a collection of interfaces it requires a driver from the database vendor on the classpath. Once added, a `java.sql.Connection` is used to send SQL queries with `java.sql.Statement`, `java.sql.PreparedStatement`, or `java.sql.CallableStatement` objects, and retrieve result sets in `java.sql.ResultSet` objects.

```java
// Loading the driver may not be necessary, but it's good to specify
try {
    Class.forName("org.postgresql.Driver");
} catch (java.lang.ClassNotFoundException e) {
    System.out.println(e.getMessage());
}

// Pay attention to the url pattern
String url = "jdbc:postgresql://host:port/database";
String username = "databaseuser"
String password = "password"

try (
    // Be sure to close all connections after use
    Connection connection = DriverManager.getConnection(url, username, password);
    Statement statement = connection.createStatement();
){
    // executeUpdate() returns the number of rows affected for DML
    int rowCount = statement.executeUpdate("insert into pizza values (1, 'cheese')");

    // executeQuery() returns a ResultSet object for queries
    ResultSet pizzas = statement.executeQuery("select * from pizza");

    // Loop through ResultSet for each row returned
    while(pizzas.next()) {
        System.out.println(pizzas.getInt("id"));
        System.out.println(pizzas.getString("flavor"));
    }

} catch (SQLException ex) {
    
} 
```

# Password credentials
Hardcoding url, username, and password is not secure, especially once your source code is pushed to public repositories online. An alternative is to save your information to a properties file:

### connection.properties
```
url = jdbc:postgresql://host:port/database
username = databaseuser
password = password
```

Then, in your Java application, load in the properties using `java.util.Properties`
```java
Properties properties = new Properties();
properties.load(new FileInputStream("connection.properties"));

String url = properties.getProperty("url");
String username = properties.getProperty("username");
String password = properties.getProperty("password");
```
Then simply remember to never add your `connection.properties` file to your git repository.

# SQL CLI program
A demonstration of various JDBC methods
```java
String url = "jdbc:postgresql://host:port/database";
String username = "databaseuser"
String password = "password"
String sql;

// Connect to a Postgres instance and set Scanner to stdin
try (Connection connection = DriverManager.getConnection(url, username, password);
        Scanner scanner = new Scanner(System.in);) {
    // Loop after each user input
    while (true) {
        Statement statement = connection.createStatement();
        System.out.print("sql> ");
        sql = scanner.nextLine();
        if (sql.equalsIgnoreCase("quit"))
            break;

        // Statement.execute(String query) returns true if ResultSet
        boolean isResultSet = statement.execute(sql);
        if (isResultSet) {
            // Get and print column names from metadata
            ResultSet resultSet = statement.getResultSet();
            ResultSetMetaData rsmd = resultSet.getMetaData();
            for (int j = 1; j <= rsmd.getColumnCount(); j++) {
                System.out.print(rsmd.getColumnLabel(j) + "\t");
            }
            System.out.println();

            // Get and print column values from ResultSet
            while (resultSet.next()) {
                for (int i = 1; i <= rsmd.getColumnCount(); i++) {
                    System.out.print(resultSet.getString(i) + "\t");
                }
                System.out.println();
            }
            resultSet.close();
        } else {
            // If other DML, return rows affection
            System.out.println(statement.getUpdateCount() + " rows affected");
        }         
        statement.close();
    }

} catch (SQLException e) {
    e.printStackTrace();
}
```

## Statement
A Statement object sends queries and updates, as well as receive errors or ResultSets.

**Statement** is prone to SQL Injection attacks, especially if you use a raw string to write the query.

**PreparedStatement** is a precompiled SQL statement. It is best used for writing several similar queries in a loop, but will also as a side effect protect against SQL Injections
```java
PreparedStatement ps = myConnection.prepareStatement("UPDATE ANIMALS SET name=? WHERE id=?");
ps.setString(1, "Hippo");
ps.setInt(2, 7);
ps.executeQuery();
```
**CallableStatement** execute stored procedures and can return 1 or many ResultSets.
```java
CallableStatement cs = myConnection.prepareCall("{CALL BIRTHDAY_SP(?, ?)}");
cs.setInt(1, aid);
cs.setInt(2, yta);
cs.execute();
```

# Collections API
* Collections Framework in Java is a set of classes and interfaces that implement commonly used data structures
* Important interfaces: `List`, `Set`, `Map`, `Iterable`, `Collection`, abstract classes, and classes
* A collection is a single object which acts as a container for other objects

## ```List<E>``` - Interface
    * ordered => preserves the order in which inserted
    * duplicate entries allowed
    * elements accessed by index

### ```ArrayList<E> implements List<E>```
    * resizable array
    * traversal is fast (constant time)
    * insertion/removal is slow (linear time, since there is a risk of having to resize the underlying array)

### ```LinkedList<E> implements List<E>, Queue<E>```
    * implements both List and Queue => has all methods in both interfaces
    * insertion/removal is fast (no risk to resize)
    * traversal is slow for an arbitrary index

### ```Vector<E> implements List<E>```
    * Old school, essentially a thread-safe implementation of an ```ArrayList```

### ```Stack<E> implements List<E>```
    * Old school, should use an ```ArrayDeque``` for the Stack data structure

## ```Set<E>``` - Interface
    * NOT index driven
    * Unique elements allowed only
    * DOES NOT preserve the order in which they were inserted

### ```HashSet<E> implements Set<E>```
    * Backed by a HashMap<K, V>
    * Guarantees no ordering when iterating
    * Allows one null value
    * Insertion/Traversal are fast
    * Tradeoff is that it does not maintain order in which you insert elements

### ```TreeSet<E> implements Set<E>```
    * Backed by a Sorted Tree
    * Main benefit is that they maintain sorted order
    * Tradeoff is that insertion/removal are slow, because the elements must maintain sorted order
    * Cannot contain any null values, since null cannot be compared to any object

## ```Queue<E>``` - Interface
    * Used when elements should be added and removed in a specific order
    * Unless specified, elements are ordered FIFO

### ```ArrayDeque<E> implements Queue<E>```
    * Pronounced as 'deck'
    * Implementation of a pure double-ended queue
    * Stores elements in a resizable array
    * can be implemented as either a Queue or a Stack
    * If Queue, we use offer/peek/poll
    * If Stack, we use push/poll/peek
    

### ```ArrayDeque<E>``` Methods
| Operation | Throws Exception | Returns null |
| --------- | ---------------- | ------------ |
| Insert    | ```boolean add(E e)```|```boolean offer(E e)```|
| Remove    | ```E remove()``` | ```E poll()``` |
| Examine   | ```E element()```| ```E peek()```|
```void push(E e)``` is for a Stack (LIFO), which adds elements to the front of the queue

## ```Map<K, V>``` Interface
    * Used to identify a value by a key, each element in a map is a Key-Value pair
    * NOTE: Map does not implement the Collection interface, however it is considered to be part of the Collections framework

### ```HashMap<K,V> implements Map<K,V>```
    * Stores elements in key-value pairs
    * Insertion/Retrieval of elemeny by key is fast
    * Tradeoff is that it does not maintain the order of insertion
    * Permits one null key and null values

### ```TreeMap<K,V> implements Map<K,V>```
    * Keys are stored in a Sorted Tree structure
    * Main benefit is that keys are always in a sorted order
    * Insertion/Retrieval are slow
    * Cannot contain null keys as null cannot be compared for sorting

### ```Hashtable<K,V> implements Map<K,V>```
    * Old school, thread-safe implementation of a HashMap
    * Does not allow null keys or null values

# Iterator
* interface
  * `hasNext`, `next`, `remove`
* creator of collection is responsible for implementing `Iterator`
  * `next` is guaranteed **O(1)**
* can use if collection **is a** `Iterable`

common looping idiom

```
List<Integer> list = new ArrayList<>();
list.add(10);
list.add(20);
list.add(30);

Iterator<Integer> iterator = list.iterator();

while(iterator.hasNext()) {
  Integer temp = iterator.next();
}
```

# I/O Streams
The JVM can connect to sources of data that exist outside itself, from files on the hard drive to network port sockets and of course the standard input/output channels of a console.
- Byte Input Streams
    - **BufferedInputStream** Reads a buffer of bytes from an InputStream, and then returns bytes from the buffer, making small reads more efficient.

    - **ByteArrayInputStream** Reads bytes sequentially from an array.

    - **FileInputStream** Reads bytes sequentially from a file.

    - **ObjectInputStream** Reads binary representations of Java objects and primitive values from a byte stream. This class is used for the deserialization of objects.

- Byte Output Streams
    - **BufferedOutputStream** Buffers byte output for efficiency; writes to an OutputStream only when the buffer fills up.

    - **FileOutputStream** Writes bytes sequentially to a file.

    - **ObjectOutputStream** Writes binary representations of Java objects and primitive values to an OutputStream. Used for the serialization of objects.

- Character Input Streams
    - **BufferedReader** Reads a buffer of characters from a Reader, and then returns characters from the buffer, making small reads more efficient.

    - **FileReader** Reads characters sequentially from a file. An InputStreamReader subclass that reads from an automatically-created FileInputStream.

    - **InputStreamReader** Reads characters from a byte input stream. Converts bytes to characters using the encoding of the default locale, or a specified encoding.

- Character Output Streams
    - **BufferedWriter** Buffers output for efficiency; writes characters to a Writer only when the buffer fills up.

    - **FileWriter** Writes characters sequentially to a file. A subclass of OutputStreamWriter that automatically creates a FileOutputStream.

    - **OutputStreamWriter** Writes characters to a byte output stream. Converts characters to bytes using the encoding of the default locale, or a specified encoding.

    - **PrintWriter** Writes textual representations of Java objects and primitive values to a Writer.

# Java build artifacts
* zip files
* it is easier to pass around a single, compressed file

# Java Archive (JAR)
* collection of `.class` files

# Web Archive (WAR)
* JARs, HTML, CSS, JavaScript

# Enterprise Archive (EAR)
* WARs, EJBs

# Unchecked Exceptions
* do not have to handle, but can
* programming mistakes
* examples: `NullPointerException`, `ArithmeticException`, `ArrayIndexOutOfBoundsException`

# Checked Exceptions
* you have to handle
* examples: `IOException`, `SQLException`

# Marshaling
* convert object to language agnostic data format: xml, json, yaml, ...

#Servlet 
HTTP/HTML
Hypertext Transfer Protocol & Hypertext Markup Language, the two main technologies for a web browser. HTML provides a structure for static content on web pages. HTML documents are organized by element tags, some with attributes. Browsers don't display the element tags, but instead parse them to render content.

<html>
    <body>
        <p>Hello there!</p>
        <a src="www.google.com">Google</a>
    </body>
</html>

HTTP is all about sending and receiving documents. A document is abstracted from HTTP packet that has information like metadata, contents, status codes.

# JavaEE
Java Enterprise Edition, this is a community driven collection of Specifications, APIs and Frameworks which provide enterprise functionality. We will start with Java Servlets, a JavaEE API for communicating between a Java code base and HTTP.

Found in `javax.servlet` and `javax.http` the Servlet API provides a `Servlet Interface` which is implemented by the `GenericServlet Abstract Class`, then the `HTTPServlet Abstract Class`, and then finally allows you to extend the HTTPServlet.

In a normal servlet process:
- The client sends an HTTP Request to a (Servlet) Web Container, which is a Java Server that is running your application. We will be using Apache Tomcat, which is Apache's lightweight implementation of the JavaEE Server and Servlet Container spec.
- Your Tomcat server will have your application in its webapps folder (as a war, usually), and this application will have the following:
    - *src/*: for the servlet and other business logic code
    - *webapp/*: for any hosted HTML-related files, as well as:
    - **Deployment Descriptor**: commonly a *web.xml* file that maps incoming requests to your Servlets.
- Java application on Tomcat will handle Request as well as the Response by creating Java objects to model the Request/Response.

## Servlet - Lifecycle
The Tomcat server will handle the control flow of your application through a servlet lifecycle process.
1. When a request comes in, the container instantiates any appropriate servlets
1. Once instantiated the container initializes the servlet by invoking its `init()` method
1. After initialization (or existing servlet is found), the container invokes `service()` to process the request.
    1. public void service (ServletRequest req, ServletResponse resp) {...} *
    1. protected void service (HttpServletRequest req, HttpServletResponse resp) {...} *
    1. protected void doGet (HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {...} *
1. Response object is returned to client
1. When the container shuts down or needs to conserve memory or just because a servlet's stated lifespan is reached, the container will call the `destroy()` method of your servlet.

Container calls init() once, service() many times, and eventually destroy() once.

## WAR
JEE web applications are usually packaged as `.war` files, a web archive similar to a `.jar` but with some minor changes to folder heirarchy. A `src/main/webapp` folder becomes the root directory, and the archive is usually hosted on a Java web server such as **Apache Tomcat**. Be sure to set the `packaging` property in your `pom.xml` to `war`:
#### pom.xml
```xml
...
<packaging>war</packaging>
...
```

## Dependencies
To begin using Java Servlets, include the following dependency to your Maven `pom.xml`:
#### pom.xml
```xml
...
<groupId>javax.servlet</groupId>
<artifactId>servlet-api</artifactId>
<version>2.5</version>
...
```
`Servlet` is a JEE specification which is not included in Java's standard library, so it must be imported or the project must use a JDK with JEE libraries included already.

## Deployment Descriptor
A Java server like Tomcat will deploy a web archive and register all servlets according to the *deployment descriptor* found in `src/main/webapp/WEB-INF/web.xml`:
#### web.xml
```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://java.sun.com/xml/ns/javaee" xsi:schemaLocation="http://java.sun.com/xml/ns/javaee http://java.sun.com/xml/ns/javaee/web-app_2_5.xsd" version="2.5">

...

</web-app>
```
Servlets, Filters, Context parameters, and other configurations are declared and defined in the `web.xml` 

## Servlet Mapping
Servlet classes are registered in the `web.xml` by assigning a name to both a url mapping and the fully qualified class name of the Servlet:
ServletContext contains config for all servlets
ServletConfig contains config for one servlet
#### web.xml
```xml
...
<servlet>
    <servlet-name>myServlet</servlet-name>
    <servlet-class>servlets.MyServlet</servlet-class>
</servlet>

<servlet-mapping>
    <servlet-name>myServlet</servlet-name>
    <url-pattern>/myServlet</url-pattern>
</servlet-mapping>
...
```
This will provide access to the servlet through its url mapping, in the above case at `http:[hostname]:[port]/[app-context]/myServlet`

## Servlet
The Servlet API provides the `HttpServlet` abstract class which can be extended to define your own custom behavior:
#### MyServlet.java
```java
package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MyServlet extends HttpServlet {
  @Override
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    throws ServletException, IOException {
            // Implements GET behavior
  }
  
  @Override
  protected void doPost(HttpServletRequest req, HttpServletResponse resp)
    throws ServletException, IOException {
            // Implements POST behavior
  }
}
```
The `HttpServletRequest` object provides useful methods such as `getParameter(String name)` which returns the value of a Query or post body parameter. `HttpServletResponse` provides a `getWriter()` method which returns a `PrintWriter` object to append data to the response body.

## Servlet 3+
More recent versions of the Servlet API offer convenience annotations that allows configuration in a decorator over the Servlet class itself, leaving the `web.xml` blank for the most part:

#### pom.xml
```xml
...
<groupId>javax.servlet</groupId>
<artifactId>javax.servlet-api</artifactId>
<version>3.0.1</version>
<scope>provided</scope>
...
```

#### MyServlet.java
```java
package servlets;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/myServlet")
public class MyServlet extends HttpServlet {
  protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    throws ServletException, IOException {
            // Implements GET behavior
  }
}
```

## redirect
* sends a 301 response
* total of 2 requests/responses, changes url

```
response.sendRedirect("dog.html");
```

## forward
* sends response directly
* only 1 request/response, url does not change

```
request.getRequestDispatcher("dog.html").forward(request, response);
```

## PrintWriter
* manually write response

```
String name = "john";

PrintWriter printWriter = response.getWriter();

printWriter.write("<h1>hello from " + name + "</h1>");
printWriter.write("<p>this seems like a neat way of doing things</p>");
```
## Session
* a user using a site for a time period (until 30 minutes inactive)
* allows us to store data between requests

## Cookies
* file on the client's computer
* `JSESSIONID` is a cookie that holds a user's unique session id


#Angular

A framework for building client applications in HTML, CSS, and JavaScript/TypeScript, MVC design pattern, SPA (Single Page Application).

## Why Angular? 
### Why not JavaScript or jQuery?

Sure we can, and that is actually how many web applications are built. However as our applications get more complex, vanilla JS/jQ code becomes harder to maintain.

Angular (nG) provides us with a way to properly structure or code, without having to understand complex JS design patterns (i.e. Revealing Module or Prototype patterns)

Applications built with JS/jQ are also more difficult to test, and nG simplifies this task.

#### Benefits of nG

* Gives our applications a clean structure
* Includes a lot of reusable code
* Makes our applications more testable (both unit and integration testing)

# Structure of an Angular Application

* e2e 
    * End-to-end tests are automated tests that simulate a real user's interaction with our web page

* node_modules
    * the storage location of all of the third-party libraries our nG application depends upon
    * only used for development

* src
    * the actual source code of our nG application
    * contains the following:

        * app
            * contains a module and a component

        * assets
            * storage location for static assets for the web page (images, audio, etc.)

        * environments
            * contains configuration settings for different environment
            * contains one file for the production environment and one for the development environment

        * favicon.ico
            * icon displayed in the browser tab

        * index.html
            * a simple HTML file that contains our nG application
            * has no references to external stylesheet, since they will be added dynamically later

        * main.ts
            * starting point of the nG application
            * location where we bootstrap the application's main module using the statement:

                    `platformBrowserDynamic().bootstrapModule(AppModule);`

        * polyfills.ts
            * imports some scripts required to run nG, since nG framework uses features of JS that are
            not in the current version of JS.

        * style.css
            * the location where we can add global styles for the application (each component can have
            its own styles, as well)

        * test.ts
            * used to set up a testing environment

    * .angular-cli.json
        * configuration file for the nG CLI

    * .editorconfig
        * used to ensure that all developers working on a project have their editors configured in the
        same manner

    * karma.conf.js
        * another configuration file for a test runner known as Karma, used to testing JS code

    * package.json
        * a standard file that all Node projects have
        * contains a list of dependencies and the versions used (needed for production)
        * contains a list of development dependencies and the versions used (needed for developers only)

    * protractor.conf.js
        + a configuration file used for  the e2e testing framework Protractor
    
    * tsconfig.json
        + a settings file for the TS compiler

    * tslint.json
        + includes settings for tslint, a static analysis tool for TS code (checks TS code for readability,
        maintainability, and functionality)

    * browser validate
      * `<form ngNativeValidate></form>`

# What is Webpack?

nG CLI uses a tool known as Webpack, which is a build automation tool. Webpack is responsible for gathering scripts and stylesheets, bundling them, then minifying them for optimization.

Common bundles managed by the nG CLI (These bundles are injected into the index.html):

* polyfills.bundle.js (necessary non-standard JS features)
* main.bundle.js (nG source code)
* styles.bundle.js (stylesheets)
* vendor.bundle.js (third-party dependencies)
* inline.bundle.js (Webpack loader)

## Why no Angular3?

Angular consists of a few different libraries that are distributed as separate packages. Before Angular4 was released, the latest versions of these libraries were:

            @angular/core       v2.3.0
            @angular/compiler   v2.3.0
            @angular/http       v2.3.0
            @angular/router     v3.3.0

# Angular Fundamentals

* Components
* Templates
* Directives
* Services

# Building Blocks of Angular Applications

Now that we have some basic familiarity with nG, lets look at the building blocks of all nG applications. At the heart of every nG application are one or more *components*. Real-world applications have dozens, sometimes hundreds of components.

A component encapsulates the data, the HTML markup, and the logic of the view. Imagine we are building a website using nG. Our entire page could be viewed as one large component (`AppComponent`) that is broken into smaller sub-components (`NavComponent`, `SidebarComponent`, etc.). A key feature of our components is that they are reusable, providing a consistency in not only the look and feel of our application, but also its functionality. Additionally, the idea of using components means that we can work on smaller, more maintainable pieces of our application.

All nG applications have a root component, known as the `AppComponent`. All other components branch outward from this root component in a tree-like structure. In nG, there is also a concept of *modules* which are groupings of related components. All nG applications have at least one module, known as the `AppModule`. As our applications become larger, it may become appropriate to break our application up into smaller, more maintainable modules.


## Components (basic building block)

There are basically three steps that you need to follow in order to use a component:

1) Create the component

2) Register the component in a module

3) Add an element in the HTML markup

We have two options to choose from when it comes to creating nG components. We can either create them ourselves manually, or we can use the nG CLI to generate them automatically. The first way we will look at this is by creating them manually.

Inside of the `src` folder of our demo application (ng-demo), we will add a new file and give it the name: `courses.component.ts`. This is the naming convention you will use when creating components in nG. If your component's name has more than one word, then separate them using a hyphen.

The other, and more convenient method of creating components in nG is by utilizing the nG CLI. The following command can be used to generate a component:

    ng generate component course

The shorthand syntax for the above command is as follows:

    ng g c course

Notice that the nG CLI automatically creates a folder containing the HTML, CSS, and TS files related to our new component. It also, automatically registers the newly created component with the module we are creating it within (in this case, the AppModule). Exploring the generated files reveals that the nG CLI has automatically generated boilerplate code for us.

## Templates

We already know that a component encapsulates the data, the logic, and the HTML markup for a view. Templates are the aspects of our component that represent its presentation logic. We can use data-binding techniques such as interpolation, class binding, style binding, and two-way binding to wire the internal logic of our component to the view.

## Directives

Directives allow you to attach behavior to elements in the DOM. Directives are identified with the @Directive decorator. Directives must be present in the declarations field of your NgModule for it to be usable by another directive, component, or application

* *Component:* A directive with a template
* *Structural* A directive that manipulates the DOM
* *Attribute* A directive that manipulates the appearance or behavior of a DOM element

#### Structural Directives

We have already discussed nG components, so we will move to *structural directives*. nG includes many built-in directives that dynamically update, create, and remove elements from the DOM. These directives create the layout, look, and feel of an application. Below is a list of the built-in structural directives:

* `*ngFor`
    * used to create a copy of a template for each item within an iterable object

* `*ngIf`
    * used to display a template if a certain condition is met, otherwise remove it

* `*ngSwitch`
    * displays a template based upon the value passed to it, a default template (`ngSwitchDefault`) is provided if the value given does not match any specified cases (`ngSwitchCase`)

#### Attribute Directives

nG attribute directives modify how HTML elements look and behave. The are injected straight into the HTML and dynamically modify how the user interacts with an HTML segment. Attribute directives are so named because they loop like normal HTML attributes. Below is a list of the built-in nG attribute directives:

* `ngModel`
    * watches a variable for changes and then updates display values based on those changes

* `ngForm`
    * creates a form group and allows it to track the values and validation within that form group. By using `ngSubmit`, you can pass the form data as an object to the submission event.

* `ngStyle`
    * updates the styles of an HTML element

* `ngClass`
    * updates the class of an HTML element

## Services

Create a *service* with handles this extra functionality. We will use the nG CLI to automatically generate a service that will handle the retrieval of courses. The below command will do this:

    ng generate service courses

The shorthand syntax for this is:

    ng g s courses

`@Injectable` decorator which will allow nG to inject other services into the current service, but only if they are included in its constructor. Services can injected into components and other services as a dependencies. Doing this will allow us to keep our components and the services they use loosely coupled, and this is known as *dependency injection*.A service provides a container for reusable functionality that is readily available to nG applications.

nG comes with several built-in services that are included in the nG module, using dependency injection. Once included within a module, services can be used throughout an application. Below are the most commonly used built-in services:

* `HttpClient`
    * replaces the deprecated `http` service
    * provides a simple-to-use functionality to send HTTP request to the web server or other services

* `forms`
    * provides a service that allows for dynamic and reactive forms with simple form validation

* `router`
    * provides navigation between views and between sections within views

* `animate`
    * provides animation hooks to link into both CSS and JS-based animations

# Data Binding

Data binding is the process of linking data from a component with what is displayed in a web page. When data in the component changes, the UI rendered to the user is automatically updated. nG provides a very clean interface to link the model data to elements in a web page.

* Interpolation
    * uses the double curly braces `{{ }}` to get values directly from the component
    * Syntax: `{{ title }}`

* Property binding
    * used to set the property of a DOM object
    * Syntax: `<img [src]="myValue">`

* Event binding
    * used to handle user inputs and actions
    * Syntax: `<button (click)="myAction">Click Me!</button>`

* Two-way binding
    * used with data entry forms to receive and display data.
    * Syntax: `<input [(ngModel)]="myValue">`


## Pipes

*Pipes* are used to format data. nG comes with several built-in pipes that allow for convenient and common data transformations:

* Uppercase
* Lowercase
* Decimal
* Currency
* Percent
* DatePipe

## ng-boostrap

As an alternative to the above method of using Bootstrap, you can also leverage ng-bootstrap. ng-bootstrap is a set of components and directives that wrap up the latest version of Bootstrap. This makes it easy to use Bootstrap in our nG applications. In order to install ng-bootstrap, execute the following command:

    npm install --save @ng-bootstrap/ng-bootstrap @4.1.0

Once the installation is complete, we need to include the styles inside of the styles array found inside of our `.angular-cli.json` file. Include the following style in the array:

    "../node_modules/bootstrap/dist/css/bootstrap.min.css"


## Styles

In nG, there are a few ways to apply styles to a component:

* Using the `<style>` element inline within the HTML template
* Using the `styles` property of the component metadata to write styles inline
* Using the `styleUrls` property of the component metadata to import external stylesheets

The styles that are applied are those that come *last* in the component's metadata.

#Promise and an observable?
    ○ Observables do not execute until subscription, while promises execute upon creation.
    ○ Observables are cancellable, while Promises are not.
    ○ Promises return only one value and observables return many.
    ○ Observable - a data structure that holds the response to an asynchronous request
    ○ Promise - holds response to an asynchronous request

# Hibernate
The Hibernate framework is a ORM (Object-Relational Mapping) implementation which is built around JDBC.

ORM refers to the long-standing problem of setting up a relationship between a program's objects and rows in a SQL table.

```
class Customer {
    int id;
    String name;
    List<Account>;
}
```
```sql
Create Table Customer(
    id integer primary key,
    name varchar2(50),
    account_id foreign key references Account(id)
    --The above is an issue for mapping
);
```

Map our Java objects to database entities through Hibernate, built on top of JDBC, which will abstract for us all the persistence and transactions that we would normally do ourselves. Hibernate can use interfaces to abstract several different database connections, but can also generate SQL.

## Packages
- org.hibernate
- javax.persistence
    - JPA (Java Persistence API)
    - Generic annotations for ORMs

## Exceptions
- HibernateException
    - RuntimeException which wraps SQLException

## Dependencies
- hibernate-core
- hibernate-entityManager

## JDBC Interfaces vs Hibernate Interfaces
### JDBC
- DriverManager
- Connection
- Statement
- PreparedStatement
- CallableStatement
- ResultSet

### Hibernate
- **Configuration** creates session factories through a specified configuration file or class
- **SessionFactory** is a singleton which generates session objects using a factory design pattern.
    - >SessionFactory sf = new Configuration().configure("file").buildSessionFactory();
- **Session** represents the database connection
    - >Session s = sf.openSession();
    - >s.close();
- **Query** is used to write complex CRUD operations using HQL (Hibernate Query Language)
- **Criteria** is for programmatically writing complex Select queries
    ```java
    List<Animal> a = session.createCriteria(Animal.class)
        .addOrder(Order.asc("age"))
        .add(Restriction.between("age", 3, 7))
        .list();
    ```
- **Transaction** is an interface for managing ACID-complient transactions
    > Transaction tx = session.beginTransation();
    > //some inserts here
    > tx.commit();

## ACID
ACID is a set of rules to be respected whenever a transaction occures in a SQL database.

1. Atomicity
    - All or nothing approach, either every single line in a transaction succeeds without errors, or none do
1. Consistency
    - Every transaction must leave the database in a consistent state: respecting data, domain, and referential integrity
1. Isolation
    - All transactions that occur concurrently should create the same result in the database as if those transactions occured in series
1. Durability
    - All transactions must be permanent, leaving the database in a committed state that cannot be rolled back or lost

## Mapping with JPA Annotations
- @Entity: marks class for Hibernate
- @Table: maps entity to a table in database
- @Id: maps a property in an entity as a primary key in the database
- @Column: maps a property in an entity as a column in the database
- @JoinColumn: maps a property in an entity as a foreign key in the database

```java
//Student.java
import javax.persistence.*
@Entity
@Table(name=”student”)
public class Student(){
  @Id
  @column(name=”s_id”)
  private Integer studentId;
  
  @column(name=”s_name”)
  private String studentName;
}
```

- Multiplicity
  - @OneToOne
  - @OneToMany: used on parent relation
  - @ManyToOne: used on child relation
  - @ManyToMany

```java
@Entity
@Table(name=”dept”)
public class Department {
  @Id
  @Column(name=”d_id”)
  private Integer id;

  @Column(name=”d_name”)
  private String deptName
}

@Entity
@Table(name=”emp”)
public class Employee {
  @Id
  @Column(name=”e_id”)
  private Integer id;

  @Column(name=”e_name”)
  private String empName;
  
  @ManyToOne
  @JoinColumn(name=”dept_id”)
  private Department dept;
}
```

Alternatively, in Department.java:
```java
@OneToMany(mappedBy=”dept”)
private List<Employee> emps;
```

## Cascades
- By default, no transitive persistence or cascading of state in Hibernate objects with multiplicity relationships
- No default cascading of state or persistence by reachability
- Set up cascade types such as all, none, delete-orphan, etc, in mapping document or in annotation to establish parent/child lifecycle tables, where child lifespan is bounded by parent's lifespan

## Lazy/Eager Fetching
- Eager grabs all information, including associated objects, immediately
- Lazy grabs data only when needed, and creates a proxy in place of associated objects until then
- Proxies can be filled as long as session is open, otherwise a LazyInitializationException is thrown after session closes
- Ex: `@ManyToOne(fetch=FetchType.LAZY)`

## Object States
- Transient
  - Just Instantiated with 'new'
  - Not associated with a session
  - No database representation
- Persistent
  - Has database representation and an identifier
  - Within scope of a session
  - Any changes made in Java will be detected by Hibernate and reflected in database
- Detached
  - Was in a persistent state, but then the session ended
  - Automatic Dirty Checking
  - When connection closes, Hibernate checks for changes in persistent objects and puts all objects in Detached state
  
## Eager vs Lazy Hibernate session CRUD
- Get
  - Immediately (Eagerly) retrieve object from DB
  - Null if object does not exist
- Load
  - Retrieves a proxy (Lazily) which is filled only when used
  - Accessible while session is open

- Save
  - Returns generated PK
  - Immediately inserts regardless of transaction
- Persist
  - Void return type
  - Only inserts during a transaction

- Update
  - Updates object in DB
  - Brings transient object to persistent state
- Merge
  - Checks if object exists
  - Makes persistent object if it doesn't
  - Copies data into new persistent object

- SaveOrUpdate
  - Universal tool for persistent objects
  - If object exists, it will update
  - If not, it will create
  
## Caching
- Level 1
  - Session scope
  - Enabled by default (no config)
  - Session.evict() removes one object
  - Session.clear() removes entire cache
  - Session.contains() returns t/f if cached object is available
  
- Level 2
  - SessionFactory scope
  - Not default behavior (must configure w/ 3rd party library like Ehcache)
  - Strategies/Use cases:
    - Read_Only – good for app config, things that are never updated
    - Read_Write – for objects to be updated, only aware of changes through hibernate

# Hibernate Inheritance
– Table Per Hierarchy
  – @DiscriminatorColumn
  – @DiscriminatorValue
  – Example
    – Animal (id, name, cave)
    – Bear (weight) extends Animal
    – Bat (wingspan) extends Animal
    – Animal table:
      – id, name, cave, type, weight, wingspan (all nullable)
      – In Animal.java: @Inheritance(strategy=InheritanceType.SINGLE_TABLE)
– Table Per Subclass
  – Example
    – Animal table: id, name, cave
    – Bear table: animal_id, weight
    – Animal.java: @Inheritance(strategy=InheritanceType.JOINED)
    – Bear.java: @PrimaryKeyJoinColumn
– Table Per Class
  – Example
    – Animal table: id, name, cave
    – Bear table: id, name, cave, weight
    – Animal.java: @Inheritance(strategy=InheritanceType.TABLE_PER_CLASS)
    – Bear.java @AttributeOverrides

# Spring
Spring Framework is a highly modular Application Framework built upon an IoC Container. It offers similar features to JavaEE's EJBs and can interface well with many other specifications such as JPA. Spring can be configured and deployed without the need for an application server with only a few modules, or it can become a self-executing server in the form of a Spring Boot project.

## Inversion of Control (IoC) Container
Spring implements inversion of control through its Core IoC Container, which manages object lifecycles and automatic dependency injection. An object managed by the container, known as a **Spring Bean**, is instantiated, deployed when requested, and destroyed automatically. Any dependencies required by the bean are also injected through constructor arguments, arguments to a factory method, or properties set on the object instance after its construction. The IoC Container is known today as the Application Context, and originally called the Bean Factory.

The goal of an IoC Container is to decouple execution from configuration. By separating these concerns, an application's code base becomes more modular, loosely coupled, with less focus on how code will be implemented and more on its business logic.

The phrase 'inversion of control' refers to this process of configuring dependencies for a bean, rather than the bean controlling the process for its own dependencies.

## Modules
The IoC container is made up of the spring-core, spring-beans, and spring-context modules, but other dependent modules such as spring-aop are commonly used as well. The container can be further extended with the inclusion of other Spring frameworks such as spring-mvc, spring-data, spring-security, spring-cloud, and much more.

## Configuration
While Spring Boot consolidates many modules and follows a 'convention over configuration' approach, most Spring modules can be individually configured either through an XML file or through Java annotations. Spring Boot can load properties files and also offers native support for YAML.

Many modules provide their own preconfigured beans, but custom beans can also be configured by registering them in the XML configuration file or through annotations which are then scanned by the container. Once all beans and configuration options are gathered, an Application Context is created to act as the IoC container for a program.

The Application Context is an interface with several factories to build one according to the manner of configuration, such as ClassPathXmlApplicationContext or FileSystemXmlApplicationContext for XML files, or XmlWebApplicationContext for Spring MVC built on Tomcat. There is also AnnotationConfigApplicationContext for a configuration class.

## BeanFactory vs ApplicationContext
The Bean Factory was the original interface for Spring, and has been superceded by the more capable Application Context. Bean Factory was a sophisticated implementation of the factory design pattern which lazily and programmatically instantiate beans as singletons.

Application Context is an extension of the Bean Factory, eagerly instantiating beans and capable of defining several different scopes besides singleton.

## Bean Lifecycle
Spring's container handles the lifecycle of a bean through a complex series of steps. In general, the setup phase involves instantiation of the empty object, handling of its dependencies, initialization of properties and default values, and any custom initialization methods before the bean is ready for use within the program. The teardown phase dereferences the bean when it passes out of scope (or the container is itself shutdown), but also calls any custom destroy methods along the way.

    Lifecycle:
        ▪ Instantiate Bean
        ▪ Populate Bean
        ▪ Bean Name Aware
            • SetBeanName()
        ▪ Bean Factory Aware
            • SetBeanFactory()
        ▪ BeanPostProcessor Pre-Initialization
        ▪ afterPropertiesSet() Initialization
        ▪ (Optional) Custom Init method
        ▪ BeanPostProcessor Post-Initialization
        ▪ Bean is ready for use!
        ▪ destroy()/custom destroy method (when container is shut down)
        
As a rule, we do not need to interfere with the lifecycle, but Spring provides several callback methods to customize it in subtle ways. We can implement the InitializingBean/DisposableBean interfaces and override their afterPropertiesSet/destroy methods, or we can define our own custom init and destroy methods in XML configuration or through @PostConstruct/@PreDestroy annotations.

## Bean Scopes
A bean has several scopes, two of which are available to a basic Application Context while the rest are usually seen in a Spring web program.

| Scope | Description |
|------|------|
| singleton | (Default) Scopes a single bean definition to a single object instance for each Spring IoC container.|
| prototype | Scopes a single bean definition to any number of object instances.|
|request | Scopes a single bean definition to the lifecycle of a single HTTP request. That is, each HTTP request has its own instance of a bean created off the back of a single bean definition. Only valid in the context of a web-aware Spring ApplicationContext.
| session | Scopes a single bean definition to the lifecycle of an HTTP Session. Only valid in the context of a web-aware Spring ApplicationContext.|
| application | Scopes a single bean definition to the lifecycle of a ServletContext. Only valid in the context of a web-aware Spring ApplicationContext. |
| websocket | Scopes a single bean definition to the lifecycle of a WebSocket. Only valid in the context of a web-aware Spring ApplicationContext. |

 The most important are Singleton and Prototype for most Spring applications. Singleton is the default scope where there is one bean (of its kind) per container, which is best for stateless objects. This is not to be confused with a proper Java singleton which has hardcoded scope within a class loader. A Singleton scoped bean is cached and returned whenever that named object is requested.

 Prototype scope can have any number of instances per bean definition, and instead of caching existing beans a new instance is created for each bean request. This makes it ideal for stateful objects, but Spring no longer manages the full lifecycle for us making it little different from calling the 'new' keyword ourselves.

## Autowiring
* Let Spring figure out dependencies automagically
* types
  * default (no autowiring)
  * byName
  * byType
  * constructor

### Note
* The autowiring types **byName** and **byType** use *setter injection*

### XML Example
* Define beans in `beans.xml`
* Do not define dependencies

```xml
<bean name="beanAImpl" class="com.example.beans.BeanAImpl" autowire="byType"/>

<bean name="beanBImpl" class="com.example.beans.BeanBImpl"/>
```

```java
public class BeanAImpl implements BeanA {

  private BeanB dog;

  public void setDog(BeanB dog) {
    this.dog = dog;
  }

}
```

### Annotations example
* No longer need to define beans in `beans.xml`
* `@Component`
  * defines spring bean
  * allows it to be considered for auto-detection

```xml
<context:component-scan base-package="com.example"/>
```

```java
@Component
public class BeanAImpl implements BeanA {

  @Autowired
  private BeanB dog;

}
```

# Spring ORM
* Integrate with ORM
  * Hibernate
  * JPA
  * JDO
* Benefits
  * Easier testing
  * Easier transaction management
  * Less boilerplate code
  * many more...
* No more `hibernate.cfg.xml` - all config will be in `beans.xml`

# Contextual Sessions
* Hibernate code has no knowledge of spring
* Can still leverage DI, AOP, and other Spring features
* session which executes within the application context
* session is managed by spring (unless you configure JTA - Java Transaction API)


# Overview of integration with Hibernate
* Define 3 Spring Beans
  * DataSource
  * SessionFactory
  * TransactionManager
* Inject DataSource into SessionFactory
* Inject SessionFactory into TransactionManager
* Inject SessionFactory into all DAOs
* Use `@Transactional` to manage transactions
  * commonly used in business logic layer

# Result

### DaoImpl

```java
@Component
public class DaoImpl implements Dao {

  @Autowired
  private SessionFactory sessionFactory;

  @Override
  public FlashCard getFlashCard(Integer id) {
    Session session = sessionFactory.getCurrentSession();
    return (FlashCard) session.get(FlashCard.class, id);
  }

  @Override
  public FlashCard updateFlashCard(FlashCard flashCard) {
    Session session = sessionFactory.getCurrentSession();
    session.update(flashCard);
    return flashCard;
  }

}
```

### BusinessLogicImpl

```java
@Service
public class BusinessLogicImpl implements BusinessLogic {

  @Autowired
  private Dao dao;

  @Override
  @Transactional(readOnly=false, isolation=Isolation.READ_COMMITTED)
  public FlashCard updateAnswer(Integer id, String newAnswer) {
    FlashCard flashCard = dao.getFlashCard(id);
    flashCard.setAnswer(newAnswer);
    dao.updateFlashCard(flashCard);
    return flashCard;
  }

}
```

# Configuration

### Enable `@Transactional` annotation

```xml
<tx:annotation-driven/>
```

### DataSource

```xml
<bean id="mydataSource" class="org.apache.commons.dbcp.BasicDataSource">  
    <property name="driverClassName"  value="oracle.jdbc.driver.OracleDriver"></property>  
    <property name="url" value="#{systemEnvironment['URL']}"></property>  
    <property name="username" value="#{systemEnvironment['USERNAME']}"></property>  
    <property name="password" value="#{systemEnvironment['PASSWORD']}"></property>  
</bean>  
```

### SessionFactory

```xml
<bean id="mySessionFactory"  class="org.springframework.orm.hibernate4.LocalSessionFactoryBean">  
    <property name="dataSource" ref="mydataSource"></property>  

    <property name="packagesToScan" value="com.example.domain"/>

    <property name="hibernateProperties">  
        <props>  
            <prop key="hibernate.dialect">org.hibernate.dialect.Oracle10gDialect</prop>  
            <prop key="hibernate.show_sql">true</prop>    
        </props>  
    </property>  
</bean>  
```

### TransactionManager

```xml
<bean id="transactionManager" class="org.springframework.orm.hibernate4.HibernateTransactionManager">  
  <property name="sessionFactory" ref="mySessionFactory"/>  
</bean>  
```



## Transactions
`@Transactional` indicates that a persistence method takes place in a transactional context (i.e. on DAO methods)

<br>

### Transaction Propagation <hr>
<br>
#### REQUIRED
`@Transactional(propagation=Propagation.REQUIRED)`
- same physical transaction will be used if one already exists, otherwise a new transaction will be opened

#### REQUIRES_NEW
`@Transactional(propagation=Propagation.REQUIRES_NEW)`
- indicates a new physical transaction will be created for @Transactional method -- inner transaction can commit or rollback independently of the outer transaction

#### NESTED
`@Transactional(propagation=Propagation.NESTED)`
- inner and outer use same physical transaction, but are separated by savepoints (JDBC drivers only)

#### MANDATORY
`@Transactional(propagation=Propagation.MANDATORY)`
- existing transaction must already be opened or container will throw an error

#### NEVER
`@Transactional(propagation=Propagation.NEVER)`
- container will throw an error if a session is open (oppostite of mandatory)

#### NOT_SUPPORTED
`@Transactional(propagation=Propagation.NOT_SUPPORTED)`
- executes outside any existing transaction, current existing transaction will be paused

#### SUPPORTS
`@Transactional(propagation=Propagation.SUPPORTS)`
- executes within the scope of existing transaction
- otherwise, executes non-transactionally 

# Spring Web MVC
Spring's web framework is built on the Servlet API and deployed on its own embedded Servlet container. Centered around its Dispatcher Servlet, Spring MVC handles much of the complexity of the request-response cycle.

## MVC Design Pattern
- Model: The data being passed, rendered, and manipulated
- View: What will be displayed, usually as html
- Controller: Handles logic, routing

## Spring MVC Request-Response Flow
1. Request sent to `DispatcherServlet`
1. `DispatcherServlet` calls `HandlerMapping` for help with request URI
1. `HandlerMapping` looks up the handler for the URI, a registered `Controller` which is returned to the `DispatcherServlet` and called
1. `Controller` is the entry-point for an event in and out of the rest of the program
1. `Controller` returns a `View` name & `Model` to the `DispatcherServlet`
1. `DispatcherServlet` consults `ViewResolver` to interpret `View` name as a template file and weave the `Model` into the response body
1. Response sent to client


## DispatcherServlet
Spring MVC's front controller has its own WebApplicationContext, allowing it to handle more bean scopes than singleton and prototype. It manages Controllers, HandlerMapping, ViewResolver, and all other components.

## HandlerMapping
While configurable using `RequestMappingHandlerMapping` objects, it can be simply enabled using a `<mvc:@annotation-driven/>` element tag in configuration, allowing for component scanning to automatically register all @Controller and similar beans along with their mappings. It is responsible for routing requests to specific methods within these controllers.

## Controllers
A `@Controller` stereotype annotation registers a class as a library of methods mapped to URI paths to handle requests. Several related annotations help to further specify these requests and their expected responses.

- `@RequestMapping` specifies the URI with attributes like value for the path and method for the HTTP verb, and can be defined at the class or method level.
- `@GetMapping` is a shorthand form of a `@RequestMapping` with GET assumed as its method. Also has siblings in `@PostMapping` and similar annotations.
- `@RequestParam` can be used on method parameters to bind form or query attributes to arguments.
- `@PathVariable` can be used on method parameters to bind URI path variables to arguments.
- `@ResponseBody` tags a method (or all methods of a class) to write their return objects directly to the response body, skipping the ViewResolver entirely.

## ViewResolver
ViewResolvers handle server-side view resolution for static HTML/CSS/JS files, or rendering for dynamic templates like JSPs or Thymeleaf files. 

# Spring AOP
* Aspect Oriented Programming
* inject code
* affect many methods without having to change them
* [good reference](https://docs.spring.io/spring/docs/current/spring-framework-reference/html/aop.html)

# Aspect / Cross Cutting Concern (CCC)
* the code to inject
* good examples
  * transactions
  * security
  * logging

# Join point
* where you **can** inject
* method execution

# Pointcut
* where you **will** inject
* AspectJ pointcut expression

```java
execution(* com.example.service.EventService.play*(..))
```

# Advice
* **when** you will inject
* before
* after
* after-returning
* after-throwing
* around

# AspectJ annotations
* `@Before`
* `@After`
* `@AfterReturning`
* `@AfterThrowing`
* `@Around`

# Spring Data  (Own Project)

Spring Data’s mission is to provide a familiar and consistent, Spring-based programming model for data access while still retaining the special traits of the underlying data store.

It makes it easy to use data access technologies, relational and non-relational databases, map-reduce frameworks, and cloud-based data services. This is an umbrella project which contains many subprojects that are specific to a given database. The projects are developed by working together with many of the companies and developers that are behind these exciting technologies.

Features Powerful repository and custom object-mapping abstractions

Dynamic query derivation from repository method names

Implementation domain base classes providing basic properties

Support for transparent auditing (created, last changed)

Possibility to integrate custom repository code

Easy Spring integration via JavaConfig and custom XML namespaces

Advanced integration with Spring MVC controllers

Experimental support for cross-store persistence

# What is Spring Boot?

Spring Boot is a Spring project that takes the approach of Convention over Configuration. It makes it easy to create standalone Spring-based applications and integrates any of the other Spring projects like Web, Security, AOP, and more.

Spring Boot approaches projects with a biased view of the dependencies on your classpath and attempts to automatically configure those dependencies based on common usage. For instance, if your project includes “spring-boot-starter-web” dependencies, then Spring Boot will attempt to configure Spring MVC components like the DispatcherServlet, InternalViewResolver, DefaultHandlerMapper, and an embedded Tomcat servlet container.

### Benefits of using Spring Boot
Auto-configuration
The most glaring perk of using Spring Boot is the auto-configuration mechanism which is enabled by the annotation 
`@SpringBootApplication` is used to enable those three features:
`@EnableAutoConfiguration` enable Spring Boot’s auto-configuration mechanism
`@ComponentScan` enable @Component scan on the package where the application is located 
`@Configuration` allow to register extra beans in the context or import additional configuration classes


So what is a Spring Boot Starter?
Dependency management is a critical aspect of any complex project… so why not automate it? Spring Boot starters were built to address exactly this problem. Starter POMs are a set of convenient dependency descriptors that you can include in your application. You get a "one stop shop" for all the Spring and related technology that you need, without having to hunt through sample code and copy and paste loads of dependency descriptors. There are more than 30 available, including web (develop REST services), test (includes Spring Test, Junit, Hamcrest, and Mockito), the Data JPA starter(persistence, to be talked about more when using Spring Data), and mail (hides the complexity of dealing with the Java Mail API)

### Spring Boot CLI
Lastly, the Spring Boot CLI adds useful commands including support for running groovy scripts. It can also help with other tasks during application development.
* How does Auto-configuration work?
There is a lot of work that happens in the background when it comes to auto-configuration, but here is a short synopsis. 
  • Spring Boot will scan your application’s classpath looking for registered dependencies and according to those dependencies it can make a best guess effort on how to configure those dependencies to work based on the bias of common use. 
  • For instance, if you have “spring-boot-starter-data-jpa” Spring boot makes the effort to configure Hibernate as the application’s ORM, and it will also attempt to find a JDBC driver on the classpath and attempt to add that to Hibernate’s configuration. 

Spring Boot also allows you to override most of its auto-configuration. In the previous example, we could customize our data-jpa instance to use proper database connection credentials, driver, dialect, and any other desirable properties. This can be done in multiple ways (applications.properties, Java Configuration, and in some instances XML/YAML/JSON)

It is important to note that Spring Boot, by default, builds applications as jar files regardless of application type
Spring Boot web applications, however, can also be built as wars and deployed to a pre-installed Tomcat webserver.



# DevOps
* Automated Testing
* Continuous Integration
* Continuous Delivery
* Automated Infrastructure

# Continuous Integration (CI)
* Development practice
* Developers **integrate code into a shared repository** several times a day
* Each push triggers an **automated build**
* Allows teams to detect problems early

# Continuous Delivery (CD)
* Take CI one step further
* Development practice
* Deliver every change to a production-like environment
* Ensure business applications and services function as expected through rigorous automated testing
* Complete automation gives us confidence the application can be deployed to production with a push of a button when the business is ready

# Continuous Deployment (CD)
* Take Continuous Delivery one step further
* Pipeline deploys to production


# AWS
AWS (Amazon Web Services) is a PaaS (Platform as a Service) which offers many SaaS (Software as a Service) and IaaS (Infrastructure as a Service) IT solutions on the cloud (i.e. hosted remotely on their many server farms). Amazon offers many services at various price points and dominates the cloud IT market today.

## EC2
EC2, Elastic Cloud Compute, is a web service providing flexible computing power in the form of a server running a headless operating system on virtual hardware.An instance is a single EC2 machine with predefined hardware resources (CPU, RAM, Network I/O), and can be configured individually or as part of a group of instances in a VPC (Virtual Private Cloud). Security Group settings, Auto-Scaling groups, Load Balancers, and EBS (Elastic Block Storage) drives can be attached to each instance. When creating a new instance, users must choose an AMI from Amazon or the Amazon marketplace, attach an EBS drive, and create or assign existing key pairs for secure SSH connections to the instance in the future.

### AMI
An AMI (Amazon Machine Image) is a snapshot of a preconfigured operating system ready to be flashed onto a new EC2 instance. Amazon offers many Linux and Windows AMIs, including its own Linux distribution 'Amazon Linux', all of which come with pre-installed tools and services as well as proper security settings and user account configurations.

### Security Group
EC2 instances have strict firewall settings by default and must be configured through security group settings to allow specific kinds of traffic through specific ports or port ranges. By default a security group allows incoming SSH protocol connections on port 22.

### Auto Scaling and Elastic Load Balancing
An EC2 instance can be horizontally scaled, i.e. multiple instances sharing the same configuration can be deployed or removed to provide a small army of servers hosting multiple instances of your EC2 machine. Auto Scaling groups provide users control over hardware or network thresholds that trigger automatic scaling of the number of instances, while an ELB (Elastic Load Balancer) manages efficient routing of traffic to these instances to evenly spread traffic to available resources.

### EBS
Elastic Block Store (EBS) provides hard storage for EC2 instances, with various hardware options for desired performance and capacity. EC2 memory is volatile, so EBS offers a file storage option to back up any data on an EC2 instance. Furthermore, EBS volumes can be detached and reattached at will, and even cloned or attached to completely new instances.

EBS volumes are formatted with a file system for compatibility with an EC2 instance's operating system.

## S3
Amazon S3 (Simple Storage Service) offers an object storage service commonly used for hosting media or application files, backup storage, static website files, and software artifacts and binaries. As opposed to a block storage like EBS which includes a filesystem overhead for compatibility with Linux or Windows, an S3 simply stores objects in a bucket. An object is composed of a file and metadata while a bucket is a container hosting objects.

### Bucket Policy
An S3 bucket not only stores objects, but also provides url links to each object. The Bucket Policy for the bucket configures access permissions to these links, which are restricted by default. In the Permissions/Bucket Policy page, a JSON configuration file can be added to change it.

### Example Bucket Policy
```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Sid": "PublicReadGetObject",
      "Effect": "Allow",
      "Principal": "*",
      "Action": "s3:GetObject",
      "Resource": "arn:aws:s3:::your-bucket-name/*"
    }
  ]
}
```
This policy allows access to all files in the bucket named 'your-bucket-name'.


# Jenkins
Forked from Sun's Hudson project after it was acquired by Oracle, Jenkins is a popular open-source CI/CD tool used throughout the industry to create and manage build pipelines. Jenkins is distributed as a Java `war` package and can be deployed to a Tomcat server or run as a self-executing `war`. The Jenkins dashboard is then accessible through a web application.

# Web services
  any piece of software that makes itself available over the internet and uses a messaging system(standardized xml messaging system at the very least)
  Self contained, modular, distributed, dynamic applications that can be described, published, located, or invoked over the network to create products, processes, and supply chains. These applications can be local, distributed, or web-based.

## SOA
  Service Oriented Architecture
    Architectural pattern in computer software design in which application components provide services to other components via a communication protocol such as a network.
    
    Key Principles
      Standardized Service Contract
        Services adhere to a service description
      Loose Coupling
        Less dependency on each other
      Service Abstraction
        Hide the logic they encapsulate from the outside world
      Service Reusability
        Logic is divided into services with the intent of maximizing reuse
      Service Autonomy
        Control over the logic they encapsulate
      Service Statelessness
        Ideally, services should be stateless
      Service Discoverability
        Can be discovered in like a registry
      Service Composability
        Breaking big problems into little problems
      Service Interoperability
        Use standards that allow diverse subscribers to use the service


## SOAP
  Simple Object Access Protocol
    XML-based protocol for exchanging information working with HTTP protocol
    Only communicates through GET/POST requests
  Server-Server

    XML contains 
      Envelope element
        mandatory, encapsulate all of the data in the SOAP message
      Header element
        contains routing data/authentication info/definition of complex data types
      Body element
        definition of the web methods including any parameter information
      Fault element
        HTTP 500 errors
        fault Code
          code of the error
            versionMismatch, mustUnderstand, client, server
        fault String
          text message detailing description of error
        fault Actor
          which part/node caused the error
        detail
          specific information about what caused error

    Contract First
      Objects written from WSDL
    Contract Last
      WSDL written from Objects

    Creating a SOAP service
      Create WSDL
      Register a messages dispatcher servlet
      Write the method(s) to handle the messages and produce the response

    Creating a SOAP client
      Build all the classes from the WSDL
      Give the message a target location
      Send the message


## WSDL
  Web Services Description Language
    XML-based file which basically tells the client application the web services description
  Tags (The Pizza Man Put On Big Shoes)
    Definition
      root element of all WSDL documents
        defines name of the web service
    Types
      defines the XML schema data types used by web service
    Port
      specifies single endpoint for binding, one communication endpoint
    Message
      abstract definition of the data, contains data elements for each operation
    PortType
      abstract set of operations that can be performed and the messages involved
        "interface"
    Operation
      abstract definition of what actions are available
        "method"
    Binding
      defines the protocol and data format for each PortType
        Remote Procedure Call/Encoded
        Remote Procedure Call/Literal
        Document/Encoded
        Document/Literal
    Service
      defines the (URL) location supported by the web service
    

  Makes it easy for web service to be implemented in one programming language and called from a different programming language

  Normally consists of a message, for each web method there are two messages, input output together they form an operation

## REST
  Representational State Transfer (Architecture style that defines a set of constraints to be used for creating web services)
    Used to build Web Services that are lightweight, maintainable, and scalable in nature
  The architecture is client/server, stateless, layered, and supports caching
  Principles of REST
    resource
      is any object the API can provide information on. Each resource has a unique identifier. The ifentified can be a name or a number
    representation
      JSON, XML, or some other transferred data representation of the resource 
    messages
      the use of explicit HTTP methods
  RESTful service
    service built on REST architecture
      Uniform Interface
        similiar approach for other API (GET/PUT/POST/DELETE operations)
      Client-Server independence
      Stateless
        server does not keep track of prior requests(sessions)
      Cacheable
      Layered System
      Code on demand
  Methods 
    GET: retrieve an object, idempotent/safe 
    PUT: update/replace an object, idempotent 
    POST: create an object, not idempotent 
    DELETE: delete an object, idempotent 

## Differences between SOAP & REST
  Security - SOAP has built in security; REST has only HTTPS 
  Protocol - SOAP can use almost any protocol; REST can only use HTTP and HTTPS 
  Atomicity - SOAP has built in transactions; REST does not perform atomic transactions, just represents state 
  Contract - SOAP is contract-based (WSDL); REST is not (but could be with a WADL) 
  Exception handling - SOAP has built in exception handling; REST needs external exception handling (i.e. Spring) 
  Tools - SOAP uses Apache-CXF(Apache crossfire); REST is tool-less 
  Message - SOAP uses only XML; REST allows JSON, XML, and other media types.
  Bandwidth - SOAP requires more bandwidth for its usage; REST does not need much bandwidth when requests are sent to the server

## When to use REST/SOAP
  Use REST
    Limited resources and bandwidth
    Statelessness 
      no need to maintain a state of infomation from one request to another
    Caching
    Ease of coding
      REST services and subsequent implementation is far easier than SOAP

  Use SOAP
    Asynchronous processing and subsequent invocation
      there is a requirement that the client needs a guaranteed level of reliability and security
    Formal means of communication
      Both client and server have an agreement on the exchange format
    Stateful operations
      Application has a requirement that state needs to be maintained from one request to another

# Microservices
  A service oriented architecture pattern wherein applications are built as a collection of various smallest independent service units. Approach to decompose an application into single-function modules with well-defined interfaces. These modeules can be independently deployed and operated by small teams.

  Stateless
  Stateful

## Monolithic App
  built as a single container unit application which all the software components of an application are clubbed into a single package

# Main advantages of using microservices.
  Services are independently deployable and scalable

  It allows for different services to be written in different programming languages.

  Scalability and reusability

  Work well with containers such as Docker

  Better fault isolation
    if one microservice fails, the other will continue to work
  
  Handling traffic well 
    instances of services created as needed

  Loose coupling 
    Less dependency on each other

# Any disadvantage in using microservices.
  DevOps complexity
    Due to several moving parts of the application. It becomes complex.

  Increased Resource use 
    Initial investment to run these applications are high because all the independently running components need their own containers

  Ease overhead
    people need to communicate to make sure update doesn’t occur error on other services, Cost to monitor each individual service

  Databases are more difficult to keep normalized

## what is a messaging queue? how do they work?
  A messaging queue is a software component used for passing messages between services that are tightly coupled as services themselves cooperate  with other services. Messages are persisted as with microservices failues are isolated. Messageing queues work by facilitating asynchronous communication between discrete services. Where Messages are stored on the queue until they are processed and deleted. Each message is processed only once, by a single consumer and this operation is decoupled. Message queues can be used to decouple heavyweight processing, to buffer or batch work, and to smooth spiky workloads.

## what is a circuit breaker? how does it work
  Circuit breaker is a pattern that helps prevent catastrophic cascading failure across multiple systems. The concept there is a protected function call in a circuit breaker object, which monitors for failures. Upon failure the circuit breaker trips and all further calls to the circuit breaker return with an error, all of this is done without involving the protected call being made. There are three states of a circuit breaker:
    Closed
      Everything is normal, circuit breaker remains in the closed state and all calls pass through to the services

    Open
      A number of failures occur and the circuit breaker returns an error for calls without executing the function

    Half-Open
      After a timeout period, the circuit switches to half-open to test if the underlying problem still occurs. If a single call fails it will then go back to the Open state, if it succeeds it will then head to the closed state.
  Circuit breaker is a great tool for ensuring service availability


# Eureka
  *Eureka is a service discovery pattern implementation
  *Microservice is registered in the server
  *Client microservice looks up the server to get dependent microservice
Eureka is a REST (Representational State Transfer) based service that is primarily used in the AWS cloud for locating services for the purpose of load balancing and failover of middle-tier servers.
Annotations: `@EnableDiscoveryClient` / `@EnableEurekaClient @EnableEurekaServer`

# Zuul
Edge/Gateway service that proxies requests to multiple backing services, providing dynamic routing, monitoring, resiliency, security and more.

Receives all incoming requests and delegates requests to internal micro-services through the Eureka Server.
Annotations: `@EmableZuulProxy`

# Spring Cloud Config Servers
* “Spring Cloud Config provides server and client-side support for externalized configuration in a distributed system.”
* Spring Config Server is built on Spring Boot
* Spring Cloud Config Server provides an HTTP resource-based API for external configuration
* Allows client applications to consume configuration on startup and can refresh the configuration without restarting.
* Spring Cloud Config works best with Spring applications, but can also work with any application running any language.

# Hystrix
* A circuit breaker module developed by *Netflix* in 2011.

* The Netflix API processes 10+ billion Hystrix Command executions per day using thread isolation.


## Hystrix and Defensive Programming:
* **Timeout** - Hystrix does not wait longer than the configured timeout for a response.

* **Limited Thread Pool** – a thread pool prevents threads from being exhausted. 

* **Circuit Breaker Pattern** 

    CircuitBreakerRequestVolumeThreshold # of fails before tripping

  CircuitBreakerSleepWindow 4,000ms by default – time after which the request to the remote service will be               
        resumed. Gives time for app to recover.

## Fallbacks
* Use fallbacks when failures occur to keep app running

* Provide fallback logic with HystrixCommand.getFallback() which returns a single fallback value. `@HystrixCommand`

# Tx Propagations

defines the tx scope (also called *tx attributes*)
* Required - Supports a current transaction; creates a new one if none exists.
* Requires_new - Creates a new transaction, suspending the current transaction if one exists.
* Supports - Supports a current transaction; executes non-transactionally if none exists.
* Not_supported - Does not support a current transaction; rather always execute nontransactionally.
* Mandatory - Supports a current transaction; throws an exception if no current transaction exists.
* Never - Does not support a current transaction; throws an exception if a current transaction exists.
* Timeout_default - Uses the default timeout of the underlying transaction system, or none if timeouts are not supported.
* Nested - Executes within a nested transaction if a current transaction exists.

# HTTP Status Codes
- 100-199: INFO
- 200-299: OK/Success
- 300-399: Redirect
- 400-499: Error/Request Incomplete
- 500-599: Server Error

# HTTP Methods (Verbs)
  Idempotent - no side effects if identical request made multiple times
  Safe - read-only operation, doesn't alter the state of the server
  - GET: retrieves information, sends info in the URL itself, empty body >localhost:8080/ExampleContext/example?name="bob"
  - HEAD: Requests the headers that are returned if the specified resource would be requested with an HTTP GET method
  - OPTIONS: Describes the communication options for the target resource
    Not Safe, but Idempotent
      - PUT: Send data to a server to create/update a resource
      - DELETE: Deletes the specified resource
  Not Idempotent
 - TRACE: Performs a message loop-back test along the path to the target resource
 - POST: Send data to a server to create/update a resource
 - PATCH: Applies partial modifications to a resource
 - CONNECT: Starts two-way communications with the requested resource

# Http Request
    * Verb – Http Method
    * URI – Uniform Resource Identifier, identifies resource on server
    * Version – Http version
    * Header – Meta data, key-value pairs, formatting, other details
    * Body – Message content or resource representation

# Http Response
    * Status – Indicates success or failure, between 100-599
    * Version
    * Header – Meta data, key-values (content length, timestamp, content type, etc)
    * Body

Annotations to know
  * Web Service
    - @WebService
    - @WebMethod
  * Spring
- @Autowired
    - @Bean
    - @Transactional
    - @Scope
    * Stereotypes
      - @Service
      - @Repository
      - @Component
      - @Controller - by default returns the name of a view, so that the View Controller can resolve a view.
    - MVC
      * @RestController - returns a HttpResponse by default
      * @RequestMapping – gives more direction to the url pattern
      * @PathVariable – allows you pass in a variable into your url mapping. The annotation ins {} and this allows you to pass in a variable into your request method.
      * @RequestsParam
      * @ModelAttribute
      * @SessionAttributes
      * @RequestBody/@ResponseBody

    - AOP
      * @Aspect
      * @Around
    - Data
      * @Entity
      * @Table
      * @Column
      * @ID
      * @OneToOne/@OneToMany/@ManyToOne/@ManyToMany
      * @GeneratedValue
    - Security
      * @PreAuthorize
    - Boot
      * @EnableAutoConfiguration
      * @SpringBootApplication
  * Eureka
    - @EnableEurekaServer
    - @EnableEurekaClient
  * Zuul
    - @EnableZuulProxy
    -@EnableDiscoveryClient

