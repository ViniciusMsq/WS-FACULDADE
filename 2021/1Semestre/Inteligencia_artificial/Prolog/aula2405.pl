% livro(Titulo, Ano, Autor).
livro('O Cortico', 1890, 'Aluisio Azevedo').
livro('Memorias de um Sargento de Milicias', 1862, 'Manuel Antonio de Almeida').
livro('A Cidade Sitiada', 1948, 'Clarice Lispector').
livro('A Hora da Estrela', 1977, 'Clarice Lispector').
livro('Navio Negreiro', 1868, 'Castro Alves').
livro('Iracema', 1865,'Jose de Alencar').

cargo(tecnico,rubens). 
cargo(secretaria_executiva,bete).
cargo(tecnico,yvone). 
cargo(diretor,paulo).
cargo(engenheiro,chandler). 
cargo(engenheiro,renato). 
cargo(engenheiro,huei). 
cargo(engenheiro,walter). 
cargo(engenheiro,ana). 
cargo(supervisor,luis). 
cargo(supervisor_chefecarla).
chefiado(secretaria_executiva,diretor).
chefiado(supervisor_chefe,diretor).
chefiado(supervisor,supervisor_chefe).
chefiado(analista,supervisor).
chefiado(engenheiro,supervisor).
chefiado(tecnico,engenheiro).

origin(ba137, chicago). 
origin(twa194, dallas). 
origin(pa100, london). 
origin(az129, london). 
chegada(ba137, 1250).             
chegada(twa194, 2200). 
chegada(az129, 2200).
saida(pa100, 1330).
saida(twa194, 1900).
saida(ba137, 1040).
destination(az129, pisa).
destination(pa100, rome).
destination(twa194, paris).
destination(ba137, london).