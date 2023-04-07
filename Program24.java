import java.util.*;
import java.io.*;

class Program24
{
    public static void main(String arr[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter file name : ");
        String filename = sobj.nextLine();

        File fobj = new File(filename);

        boolean bobj = fobj.createNewFile();
        if(bobj == true)
        {
            System.out.println("File is successfully created");
        }
        else
        {
            System.out.println("Unable to create file");
        }
    }
}