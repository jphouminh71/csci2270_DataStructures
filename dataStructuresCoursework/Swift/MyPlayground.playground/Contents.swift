/*
 Notes:
 think of swift as a simpler version of C++ for things such as
 you dont need to have a main function
 syntax:
 let <== This is used before variable declarations but using this specifies that the variable is a constant
 var <== declares ANY type of variable
 \(n) <== using this inside print statements and it allows you to include variables without having to convert them into type string, such as doing string(myintvalue)
 */
import Cocoa

//print("Hello World")        // print statements
//
let strawberries = 10
//strawberries = 9 this throws an error because you tried to update a constant
//strawberries = strawberries - 1;  same thing here, LET represents constant
let oranges = 100
var fruits = strawberries + oranges
//print("There are", fruits, "fruits in the basket")
//print("There are \(fruits) fruits in the basket")   // different method for including variables in print statements
var pinapples = 10
var pinapple: Double = 10           // this is how you would declare explicit variable types
var floatNum: Float = 10
var stringVal: String = "Hello"
var charVal: Character = "c"        // you dont use single quotes for declaring character values

//print(pinapple) // printing the variable pinapple as a float value


// practicing concatonating strings and working with arrays

var string1 = "hello"
var string2 = "world"
//print(string1,string2)      // spaces are automatically inputted if you try to print out two different variables seperating them by a comma
//print(string1+string2)
//print(string1,"",string2)

var shoppingList = ["Wrx Sti", "Lexus RCF"]
//print(shoppingList[0])      // accessing array elements is the same as if you would in a c++
//print(shoppingList[1])
var stringConcatonation = shoppingList[0] + " " + shoppingList[1]
//print(stringConcatonation)                                          // concatonating string variables

var OccupationArray = [
    "Jonathan": "Coder",
    "Rick": "Character"
]
var SampleArray = [1.0,2.0,3.0,4.0,5.0]
//print(SampleArray[0] + SampleArray[3])
//print(OccupationArray["Jonathan"])

//              While Loops and For Loops

var counter = 0                 // while loop syntax
while counter <= 10{
    //print(counter)
    counter+=1
}

for _ in 1...10{          // for loop syntax , similar to python
    //print(counter)
}

var Names = ["Jonathan" , "Jacob" , "Amanda", "Jewels" , "Master"]

var i = 0
for _ in Names{
    //print("Hello, ", Names[i])
    i+=1
}

//      Recap , while loops are essentially the exact same, and the for loop is like python but instead of in range you would use ... or a var with some value like an array

let Score = [1.3,1.8,1.9,2.0]       // flow control with a for loop
var size = 4
var j = 0
for _ in Score{
    if Score[j] < 2.0{
        //print("value was less than 2.0")
        j+=1
    }
    else{
        //print("It was greater")
        j+=1
    }
}

var u = 0
while u < size{
    if Score[u] < 2.0{
        //print("Value was less than 2.0")
        u+=1
    }
    else{
        //print("Value was greater than 2.0")
        u+=1
    }
}

for index in Score{         // here it is actually pulling from the array
    //print(index)
}

var currentIndex = 0
while currentIndex < size{
    print(currentIndex)
    currentIndex+=1
}












