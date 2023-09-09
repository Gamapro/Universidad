import java.util.HashMap;
import java.util.*;
import java.io.*;
        
public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        HashMap<String, String> diccionario = new HashMap<String, String>();
        int n = 5;
        for(int i = 0; i < n; ){
            System.out.println("Ingresa una llave y clave");
            String llave = sc.nextLine();
            String valor = sc.nextLine();
            if(diccionario.containsKey(llave)){
                System.out.println("Ya existe esa llave");
            }else{
                System.out.println("Insertado exitosamente");
                diccionario.put(llave, valor);
                i++;
            }
        }

    }
}