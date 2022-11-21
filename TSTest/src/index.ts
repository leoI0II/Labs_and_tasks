// function BuildArray()
// {
//     let array = [];
//     array.push(11);
//     array.push("hello");
//     return array;
// }

// let arr = BuildArray();
// arr.push("world!");
// arr.push(1111);


// enum langs
// {
//     eng = 2,
//     it,
//     ru,
//     ua,
//     chinese
// };
// console.log(langs['ru'])


// let greet = function(msg : string) { console.log(msg);};
// greet('Hello world!');


// let greet: Function = (msg: string) => console.log(msg);
// greet('Hello world!');


// let greet: Function = new Function('msg', 'console.log(msg)');
// greet('Hello world!');


/*******************************************************************************************
                        !!!     IT WORKS    !!! NOTE: overloading to boolean type.
/******************************************************************************************* */
// function greet(msg?: string){
//     if (msg){
//         console.log(msg);
//     }
//     else{
//         console.log("There is nothing to log!");
//     }
// }
// greet();
/****************************************************************************************** */


/*********************************************************************************
 * WITH TYPE ALIASING TRYING TO CALL FUNCTIONS
 */

// type Context = {appID?: string, userID?: string};

// function log(message : string, context : Context = {})
// {
//     let time = new Date().toISOString();
//     console.log(time, context.appID || "app", message, context.userID || '00000000');
// }

// log('MAYDAY MAYDAY', {appID: "Flying Sim"});

/************************************************************************************** */


/*************************************************************************************
 * FUNCTIONS WITH VARIADIC ARGUMENTS: USING arguments AND REMAINING ARGUMENTS
 */

// function sumVariadic() : number{
//     return Array.from(arguments).reduce((total, value) => (total + value), 0);
// }
//sumVariadic(1, 2, 3);       // ERROR, EXPECTED 0 args, WAS GIVEN 3


/* CORRECT */

// function sumVariadic(...numbers: number[]): number{
//     return Array.from(numbers).reduce((total, value) => (total + value), 0);
// }
// console.log(sumVariadic(1, 2, 3));
/************************************************************************************** */



/*****************************************************************************************
 * FUNCTIONS - GENERATORS: THEY GENERATE A SET OF VALUES...
 */
// '*' after 'function' mean that is a generator func
function* FibonacciGenerator(){
    let a = 0;
    let b = 1;
    while (true){
        yield a;
        [a, b] = [b, a + b];
    };
}
let gen : IterableIterator<number> = FibonacciGenerator();
console.log(gen.next());
console.log(gen.next());
console.log(gen.next());

/************************************************************************************* */