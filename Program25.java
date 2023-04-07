import java.util.*;
import java.io.*;

class Program25
{
    public static void main(String arr[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter file name : ");
        String filename = sobj.nextLine();

        File fobj = new File(filename);

        if(fobj.exists())
        {
            System.out.println("File exists");
            System.out.println("File size is : "+fobj.length());
        }
        else
        {
            System.out.println("There is no such file");
        }
    }
}