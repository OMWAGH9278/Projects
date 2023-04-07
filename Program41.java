import java.io.*;
import java.util.*;

class Program41
{
    public static void main(String a[])
    {
        Scanner sobj = new Scanner(System.in);
        System.out.println("-----------------Marvellous Packer unpacker----------");

        try
        {
            System.out.println("Enter folder name which contains files which you want to pack :");
            String folderName = sobj.nextLine();

            File fobj = new File(folderName);

            System.out.println("Enter the name of packed file that you want to create :");
            System.out.println("Note : Packed file gets automatically created in current directory");

            String packFile = sobj.nextLine();

            File fpackobj = new File(packFile);
            fpackobj.createNewFile();

            FileOutputStream fout = new FileOutputStream(fpackobj);

            if(fobj.exists())
            {
                File allfiles[] = fobj.listFiles();

                System.out.println("Number of files are : "+allfiles.length);
                
                byte buffer[] = new byte[1024];
                int ret = 0, counter = 0;

                String name;

                System.out.println("--------------------------------------------");
                for(int i = 0; i < allfiles.length; ++i)
                {
                    name = allfiles[i].getName();

                    if(name.endsWith(".txt"))
                    {
                        name = name + " " + allfiles[i].length();

                        System.out.println("File name : "+name+" with length : "+allfiles[i].length()+" bytes");

                        for(int j = name.length(); j < 100; ++j)
                        {
                            name = name + " ";
                        }

                        byte headerByte[] = name.getBytes();  // String to byte array conversion

                        fout.write(headerByte, 0 , headerByte.length);  // write header in packed file
                        
                        FileInputStream fiobj = new FileInputStream(allfiles[i]);

                        while((ret = fiobj.read(buffer)) != -1)
                        {
                            fout.write(buffer,0,ret); 
                        }
                        counter++;
                    }

                }
                System.out.println("------Summary------");
                System.out.println("Number of files scanned : "+allfiles.length);
                System.out.println("Number of files packed : "+counter);
            }
            else
            {
                System.out.println("There is no such folder..");
            }
        }  // End of try
        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }
    }// end of main
}// end of class