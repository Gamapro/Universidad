import java.util.*;
import java.io.*;
        
public class PrefixPosfixHelper {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sentence = sc.nextLine();
        int x = PrefixPosfixFunction(sentence);
        System.out.println(x);
    }   

    public static int getOp(int a, int b, String op){
        int value = 0;
        if(op.equals("+")){
            value = a+b;
        }else if(op.equals("-")){
            value = a-b;
        }else if(op.equals("*")){
            value = (a*b);
        }else if(op.equals("/")){
            value = (a/b);
        }else if(op.equals("^")){
            value = ((int)Math.pow(a,b));
        }
        return value;
    }

    public static int PrefixPosfixFunction(String sentence){
        Stack<String> opt = new Stack<String>();
        Stack<Integer> val = new Stack<Integer>();
        
        String[] values = sentence.split("(?<=[-+*/()^])|(?=[-+*/()])");

        for(String s : values){

            //2. Si es un operando, pasarlo a la pila de operandos.
            if(s.matches("[0-9]+")){
                val.push(Integer.parseInt(s));
            }
            
            // 3. Si es operador:
	        // 3.1. Si la pila está vacía, meterlo en la pila operadores. Repetir a partir de 1.
            // 3.2. Si el operador es "(", meterlo en la pila operadores. Repetir a partir de 1.
	        // 3.3. Si la pila no está vacía: 
            // Si la prioridad del operador leído es mayor que la prioridad del operador cima de la pila, meterlo en la pila y repetir a partir de 1.
            // Si la prioridad del operador es menor o igual que la prioridad del operador de la cima de la pila, sacar el operador cima de la pila y utilizar los dos operandos del top para realizar la operación, incluir el resultado en la pila de operandos, volver a 3.
            // La prioridad mayor es *, ^ y /
            
            if(s.matches("[-+*/^()]")){

                if(opt.isEmpty() || s.equals("(")){
                    opt.push(s);
                }else{
                    if(s.equals("+") || s.equals("-")){
                        while(!opt.isEmpty() && !opt.peek().equals("(")){
                            String op = opt.pop();
                            int b = val.pop();
                            int a = val.pop();
                            val.push(getOp(a,b,op));            
                        }
                        opt.push(s);
                    }else if(s.equals("*") || s.equals("/") || s.equals("^")){

                        while(!opt.isEmpty() && !opt.peek().equals("(") && !opt.peek().equals("+") && !opt.peek().equals("-")){
                            String op = opt.pop();
                            int b = val.pop();
                            int a = val.pop();
                            val.push(getOp(a,b,op));
                        }
                        opt.push(s);
                    }
                }
                    
            }


            // 4. Si es paréntesis derecho:
	        // 4.1. Sacar el operador cima y utilizar los dos operandos del top para realizar la operación, incluir el resultado en la pila de operandos.
	        // 4.2. Si el nuevo operador cima es paréntesis izquierdo, suprimir el elemento cima.
	        // 4.3. Si la cima no es paréntesis izquierdo, volver a 4.1.		
	        // 4.4. Volver a partir de 1.

            if(s.equals(")")){
                while(!opt.peek().equals("(")){
                    String op = opt.pop();
                    int b = val.pop();
                    int a = val.pop();
                    val.push(getOp(a,b,op));
                }
                opt.pop();
            }   

            System.out.println("s: " + s);
            System.out.println("opt: " + opt);
            System.out.println("val: " + val);

        }

        // 5. Si quedan elementos en las pilas, realizar las operaciones hasta que queden las pilas vacías.
        while(!opt.isEmpty()){
            String op = opt.pop();
            int a = val.pop();
            int b = val.pop();
            if(op.equals("+")){
                val.push(a+b);
            }else if(op.equals("-")){
                val.push(a-b);
            }else if(op.equals("*")){
                val.push(a*b);
            }else if(op.equals("/")){
                val.push(a/b);
            }
        }

        return val.pop();
    }

}
