import java.util.*;
import java.io.*;

class Program26
{
    public static void main(String arr[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter file name : ");
        String filename = sobj.nextLine();

        File fobj = new File(filename);

        if(fobj.exists())
        {
            BufferedReader bobj = new BufferedReader(new FileReader(fobj));

            String data;

            while((data = bobj.readLine()) != null)
            {
                System.out.println(data);
            }
        }
        else
        {
            System.out.println("There is no such file");
        }
    }
}