import java.util.*;
import java.io.*;

class Program23
{
    public static void main(String arr[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter file name : ");
        String filename = sobj.nextLine();

        File fobj = new File(filename);

        fobj.createNewFile();
    }
}