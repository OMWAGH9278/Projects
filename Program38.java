import java.io.*;
import java.util.*;

class Program38
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);

        try
        {
            System.out.println("Enter folder name :");
            String folderName = sobj.nextLine();

            File fobj = new File(folderName);

            System.out.println("Enter the name of packed file :");
            String packFile = sobj.nextLine();

            File fpackobj = new File(packFile);
            fpackobj.createNewFile();

            FileOutputStream fout = new FileOutputStream(fpackobj);

            if(fobj.exists())
            {
                File allfiles[] = fobj.listFiles();

                System.out.println("Number of files are : "+allfiles.length);
                
                byte buffer[] = new byte[1024];
                int ret = 0;

                String name, header;

                System.out.println("--------------------------------------------");
                for(int i = 0; i < allfiles.length; ++i)
                {
                    name = allfiles[i].getName();

                    if(name.endsWith(".txt"))
                    {
                        header = name + " " + allfiles[i].length();
                        System.out.println(header);

                        FileInputStream fiobj = new FileInputStream(allfiles[i]);

                        while((ret = fiobj.read(buffer)) != -1)
                        {
                            fout.write(buffer,0,ret); 
                        }
                    }

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