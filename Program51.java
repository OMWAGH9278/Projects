import java.io.*;
import java.util.*;

class Program51
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
            int ret = 0, count = 0;

            File fpackobj = new File(packFile);

            FileInputStream fin = new FileInputStream(fpackobj);

            if(fpackobj.exists())
            {   
                
                byte header[] = new byte[100];

                while((ret = fin.read(header, 0, 100)) > 0)
                {
                    String strHeader = new String(header);

                    String arr[] = strHeader.split(" ");

                    File obj = new File(arr[0]);
                    obj.createNewFile();
                    System.out.println("New file dropprd named : "+arr[count]);

                    int fileSize = Integer.parseInt(arr[1]);

                    byte dataArray[] = new byte[fileSize];

                    fin.read(dataArray, 0, fileSize);

                    FileOutputStream fout = new FileOutputStream(obj);
                    fout.write(dataArray, 0 , fileSize);

                    count++;
                }

                System.out.println("Number of files unpacked successfully : "+count);
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