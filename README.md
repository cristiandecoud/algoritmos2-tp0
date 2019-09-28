# algoritmos2-tp0

## Empezar a trabajar como colaborador
#-Crear carpeta donde va a ir el proyecto.
#-Hacer git init.
#-Hacer git remote add origin "direccion web del repositorio". (Agregamos el repositorio remoto a la carpeta)
#	-Para revisar que se agrego correctamente tipear: git remote -v.
#-Hacer git pull origin master. (Descargamos el repositorio en la carpeta)
#	-Aca debe pedirnos los datos, email y contraseña.
#-Hacer git checkout -b rama-usuario (Creamos la rama para modificaciones).
#-Hacer modificaciones
#-Hacer git add .  ( agregar al stage )
#-Hacer git commit -m "Mensaje aclarando los cambios" ( commitear los cambios ).
#-Hacer git push origin rama-usuario (manda un pull request a github).
#-Ir a github, aceptar el pull request y decidir que hacer con el mismo (Merge, rebase, squash)
#-Si es merge, borrar la rama.
#-Volver a VSC y hacer un checkout master (Moverse a la rama master).
#-Los cambios no aparecen aca, estan ya subidos a github.
#-Hacer un git branch -D rama-usuario ----- IMPORTANTE ----- (Solo borrar la rama una vez se haya hecho el merge en github).
#-Hacer un git pull origin master (Descargar la modificacion subida anteriormente desde la rama, ahora al master)
#-Hacer un git lg o git log para ver las modificaciones.