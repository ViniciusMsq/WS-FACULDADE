pais(maria,jose). 
pais(joao,jose).
pais(joao,ana). 
pais(jose,julia).
pais(jose,iris).
pais(iris,jorge).
avos(X,Z):-pais(X,Y),pais(Y,Z).
filho(Y,X):-pais(X,Y).
progenitor(X,Z):-pais(X,Z).
progenitor(X,Z):-pais(X,Y), progenitor(Y,Z).