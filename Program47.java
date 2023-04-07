import java.io.*;
import java.util.*;

class Program47
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string : ");

        String str = sobj.nextLine();

        System.out.println("Enter the string to check occurence : ");

        String occur_str = sobj.nextLine();

        String arr[] = str.split(" ");

        System.out.println("Number of words are : "+arr.length);
 
        int icount = 0;
        for(int i = 0; i < arr.length; ++i)
        {
            if(arr[i].equals(occur_str))
            {
                icount++;
            }
        }
        System.out.println("Frequency of : "+occur_str+" : is : "+icount);
    }
}