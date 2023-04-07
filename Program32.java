import java.io.*;
import java.util.*;

class Program32
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        try
        {
            System.out.println("Enter folder name :");
            String folderName = sobj.nextLine();

            File fobj = new File(folderName);

            if(fobj.exists())
            {
                File allfiles[] = fobj.listFiles();

                System.out.println("Number of files are : "+allfiles.length);

                for(int i = 0; i < allfiles.length; ++i)
                {
                    System.out.println(allfiles[i].getName());
                }
            }
            else
            {
                System.out.println("There is no such folder..");
            }
        }// End of try
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }// end of main
}// end of class