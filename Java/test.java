import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Date;

import javax.sound.midi.SysexMessage;

// import java.util.Date;

// First prog in JAVA

/**
 * Testing Java...
 * @author LeXI0II
 * @version 1.0 17.05.22
 */


enum Size {S, M, L, XL};

class test{
    public static void main(String[] args) throws IOException{
        System.out.println("Hello World!!! Im ALIVE!");
        var ch = new CHECK();
        ch.func();
        System.out.println();
        // System.out.println(1_000_000);
        // System.out.println((byte)300);
        // var str_arr = new String[3];
        // str_arr[0] = "S"; str_arr[1] = "M"; str_arr[2] = "L";
        // String all = String.join(" / ", str_arr);
        // System.out.println(all);

        // toString() method works?
        // char hllo[] = {'H', 'e', 'l', 'l', 'o'};
        // hllo[0] = 'H';
        // hllo[1] = 'e';
        // hllo[2] = 'l';
        // hllo[3] = 'l';
        // hllo[4] = 'o';
        // hllo[5] = '\0';
        // System.out.println(hllo);


        


        // if ((new int[]{1, 2, 3, 4, 5})[1] == 2)
        //     System.out.println("YUP");


        // int i = 0;
        // case1:
        // while (true){
        //     case2:
        //     while (true){
        //         if (i++ > 9999)
        //             break case2;
        //     }
        //     System.out.println("Stopped 1st loop, i = " + i);
        //     if (i++ > 11999)
        //         break case1;
        // }
        // System.out.println("Stopped 2st loop, i = " + i);



        // Scanner in = new Scanner(Path.of("file.txt"), StandardCharsets.US_ASCII);
        // while (in.hasNext()){
        //     System.out.println(in.next());
        // }
        // in.close();

        // PrintWriter out = new PrintWriter("file.txt", StandardCharsets.UTF_8);
        // // nope, it doesnt append to existing file/...
        // out.append("CHECK IF APPEND IS WORKING...");
        // out.close();


        // System.out.printf("%tc\n", new Date());


        // Console cons = System.console();
        // String username = cons.readLine("User name: ");
        // char[] pass = cons.readPassword("Password: ");

        // System.out.println("Check your info:\nUser name:\t" + username);
        // System.out.print("Pass:\t"); System.out.println(pass);


        // What are code points...?
        // var str = "Hello";
        // int[] codePoints = str.codePoints().toArray();
        // System.out.println(codePoints);       

    }
}

class CHECK{
    public void func(){
        System.out.print("YES, IT WORKS!");
    }
}