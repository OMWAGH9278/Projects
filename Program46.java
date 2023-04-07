import java.io.*;
import java.util.*;

class Program46
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string : ");

        String str = sobj.nextLine();

        String arr[] = str.split(" ");

        System.out.println("Number of words are : "+arr.length);
        System.out.println("Words from string are :");

        int iMax = 0, index = 0;
        String max_str;
        for(int i = 0; i < arr.length; ++i)
        {
            if(iMax < arr[i].length())
            {
                iMax = arr[i].length();
                index = i;
            }
        }

        System.out.println("Max string is : "+arr[index]+" with length "+iMax);
    }
}