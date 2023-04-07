import java.io.*;
import java.util.*;

class Program30
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        try
        {
            System.out.println("Enter the source file name : ");
            String source = sobj.nextLine();

            System.out.println("Enter the destination file name : ");
            String destination = sobj.nextLine();

            File fsource = new File(source);
            File fdest = new File(destination);

            boolean bret = fsource.exists();
            if(bret == false)
            {
                System.out.println("Source file is not existing..");
                return;
            }

            bret = fdest.createNewFile();
            if(bret == false)
            {
                System.out.println("Unable to create destination file");
                return;
            }

            FileInputStream fiobj = new FileInputStream(fsource);
            FileOutputStream foobj = new FileOutputStream(fdest);

            byte buffer[] = new byte[1024];
            int ret = 0;

            while((ret = fiobj.read(buffer)) != -1)
            {
                foobj.write(buffer);
            }
        }// End of try
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }// end of main
}// end of class