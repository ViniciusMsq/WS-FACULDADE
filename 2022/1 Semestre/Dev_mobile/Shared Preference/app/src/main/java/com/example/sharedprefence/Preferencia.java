package com.example.sharedprefence;

import android.content.Context;
import android.content.SharedPreferences;

public class Preferencia {
    Context contexto;
    final String ARQ_PREF = "REF";
    SharedPreferences preference;
    SharedPreferences.Editor editor;
    String chaveRa = "ra";


    public Preferencia(Context C){
        this.contexto = C;
        preference = contexto.getSharedPreferences(ARQ_PREF,  0);
        editor = preference.edit();
    }

    public void salvarDados(String dados){
        editor.putString(chaveRa, dados);
        editor.commit();
    }

    public String retornarDados(){
        return preference.getString(chaveRa, "");
    }

}
