import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Data {
    
    private int dia, mes, ano;
    

    public Data(String date){
        if(validaData(date)){
            //System.out.println("Data valida");
            String str[] = date.split("/");
            this.dia = Integer.parseInt(str[0]);
            this.mes = Integer.parseInt(str[1]);
            this.ano = Integer.parseInt(str[2]);
            
        }else{
            System.out.println("Data Invalida");
    
        }
    }

    public int compara(Data data){
       
        String x = LocalDate.now().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        
        if(validaData(x)){

            String str[] = x.split("/");
            int diaCorrente = Integer.parseInt(str[0]);
            int mesCorrente = Integer.parseInt(str[1]);
            int anoCorrente = Integer.parseInt(str[2]);


            if(diaCorrente == data.getDia() && mesCorrente == data.getMes() && anoCorrente == data.getAno()){
                return 0;
            }
            if(anoCorrente > data.getAno()){
                return 1;
            }
            if(anoCorrente < data.getAno()){
                return -1;
            }
            if(anoCorrente == data.getAno()){
                if(mesCorrente > data.getMes()){
                    return 1;
                }
                if(mesCorrente < data.getMes()){
                    return -1;
                }
                if(mesCorrente == data.getMes()){
                    if(diaCorrente > data.getDia()){
                        return 1;
                    }
                    if(diaCorrente < data.getDia()){
                        return -1;
                    }
                }
            }

        }else{
            System.out.println("Data Invalida");
    
        }

        return 0;
    }
    public int compara(String data){
       
        String x = LocalDate.now().format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        
        if(validaData(x) && validaData(data)){

            String str[] = x.split("/");
            int diaCorrente = Integer.parseInt(str[0]);
            int mesCorrente = Integer.parseInt(str[1]);
            int anoCorrente = Integer.parseInt(str[2]);

            String str2[] = data.split("/");
            int diaDigitado = Integer.parseInt(str2[0]);
            int mesDigitado = Integer.parseInt(str2[1]);
            int anoDigitado = Integer.parseInt(str2[2]);


            if(diaCorrente == diaDigitado && mesCorrente == mesDigitado && anoCorrente == anoDigitado){
                return 0;
            }
            if(anoCorrente > anoDigitado){
                return 1;
            }
            if(anoCorrente < anoDigitado){
                return -1;
            }
            if(anoCorrente == anoDigitado){
                if(mesCorrente > mesDigitado){
                    return 1;
                }
                if(mesCorrente < mesDigitado){
                    return -1;
                }
                if(mesCorrente == mesDigitado){
                    if(diaCorrente > diaDigitado){
                        return 1;
                    }
                    if(diaCorrente < diaDigitado){
                        return -1;
                    }
                }
            }

        }else{
            System.out.println("Data Invalida");
    
        }

        return 0;
    }

    public Boolean isBissexto(){
        LocalDate localDate = LocalDate.now();
        int x = localDate.getYear();

        if((x%4)==0){
            if(!((x%100)==0)){
                return true;
            }
        }else{
            if((x%400)==0){
                return true;
            }
        }
        return false;
    }

    public Boolean isBissexto(int data){

        if((data%4)==0){
            if(!((data%100)==0)){
                return true;
            }
        }else{
            if((data%400)==0){
                return true;
            }
        }
        return false;
    }

    public boolean validaData(String date){
        String str[] = date.split("/");
        int diaMAX[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        try{
            int dia = Integer.parseInt(str[0]);
            int mes = Integer.parseInt(str[1]);
            int ano = Integer.parseInt(str[2]);
            
            if(dia<1 || mes<1 || mes>12 ||ano<1){
                return false;
            }
            
            if(dia > diaMAX[mes]){
                return false;
            }
            
            if(mes == 2){
                if(dia == 29){
                    boolean bissexto = isBissexto(ano);
                    if(!bissexto){
                        return false;
                    }
                }
            }

            return true; 

        }catch(Exception e){
            return false;
        }
    }

    public int getDia(){
        return this.dia;
    }
    public int getMes(){
        return this.mes;
    }
    public int getAno(){
        return this.ano;
    }
    public String getData(){
        return getDia()+"/"+getMes()+"/"+getAno();
    }
}
