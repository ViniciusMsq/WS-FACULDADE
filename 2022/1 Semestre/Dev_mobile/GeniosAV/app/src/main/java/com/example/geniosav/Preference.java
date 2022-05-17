package com.example.geniosav;

import android.content.Context;
import android.content.SharedPreferences;

public class Preference {
    Context contexo;
    final String ARQ_PREF = "REF";
    SharedPreferences preference;
    SharedPreferences.Editor editor;
    String record = "ra";

    public Preference(Context c)
    {
        this.contexo = c;
        preference = contexo.getSharedPreferences(ARQ_PREF, 0);
        editor =  preference.edit();
    }

    public void salvarDados(String dados)
    {
        editor.putString(record, dados);
        editor.commit();
    }

    public String recuperarDados()
    {
        return preference.getString(record, "");
    }
}
