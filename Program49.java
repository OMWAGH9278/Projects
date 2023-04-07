import java.io.*;
import java.util.*;

class Program49
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("-----------------Marvellous Packer unpacker----------");

        try
        {
            System.out.println("Enter the name of packed file that you want to create :");
            System.out.println("Note : Packed file should be in current directory");

            String packFile = sobj.nextLine();

            File fpackobj = new File(packFile);

            FileInputStream fin = new FileInputStream(fpackobj);

            if(fpackobj.exists())
            {   
                System.out.println("Packed file is there");
                
                byte header[] = new byte[100];

                fin.read(header, 0, 100);

                String strHeader = new String(header);

                System.out.println(strHeader);

                String arr[] = strHeader.split(" ");

                System.out.println("File name : "+arr[0]);
                System.out.println("File size is : "+arr[1]);
                File obj = new File(arr[0]);
                obj.createNewFile();
            }
            else
            {
                System.out.println("There is no such file ..");
            }
        }  
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }
}