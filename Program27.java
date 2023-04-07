import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

class Program27
{
    public static void main(String arr[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter file name : ");
        String filename = sobj.nextLine();

        File fobj = new File(filename);

        if(fobj.exists())
        {
            FileInputStream fiobj = new FileInputStream(fobj);

            byte buffer[] = new byte[100];
            int ret = 0;
            
            while((ret = fiobj.read(buffer)) != -1)
            {
                String str = new String(buffer,StandardCharsets.UTF_8);
                System.out.println(str);
            }
        }
        else
        {
            System.out.println("There is no such file");
        }
    }
}