make tp0

cd ./tests

echo "Test help command:"
../tp0 -h
echo " "

echo "Test version command:"
../tp0 -V
echo " "

echo "Test case 1: "
echo "Salida esperada: SG9sYSBjaGF1"
echo "Salida obtenida:"
../tp0 -i encoder.txt
echo " "

echo "Test case 2: "
echo "Salida esperada: Hola chau"
echo "Salida obtenida:"
../tp0 -i output-encoder.txt -d
echo " "

echo "Test case 3: "
echo "Salida esperada: Hola chau"
echo "Salida obtenida:"
../tp0 -i encoder.txt | ../tp0 -d
echo " "

echo "Test case 4: "
echo "Salida esperada: salida vacía"
echo "Salida obtenida:"
../tp0 -i empty-file.txt
echo " "

echo "Test case 5: "
echo "Salida esperada: salida vacía"
echo "Salida obtenida:"
../tp0 -i empty-file.txt -d
echo " "

echo "Test case 6: "
echo "Salida esperada: mensaje descriptivo indicando formato incorrecto"
echo "Salida obtenida:"
../tp0 -i bad-file.txt -d
echo " "

echo "Test case 7: "
echo "Salida esperada: mensaje descriptivo indicando que el archivo está en un formato incorrecto"
echo "Salida obtenida:"
../tp0 -i binary-file.bin -d
echo " "

echo "Test case 8: "
echo "Salida esperada: mensaje descriptivo indicando que el archivo no existe"
echo "Salida obtenida:"
../tp0 -i not-exist-file.txt
echo " "

echo "Test case 9: "
echo "Salida esperada: mensaje descriptivo indicando que el archivo no existe"
echo "Salida obtenida:"
../tp0 -i not-exist-file.txt -d
echo " "

echo "Test case 10: "
echo "Salida esperada: RXN0ZSBlcyB1biB0ZXh0byBkZSBlamVtcGxvIHBhcmEgZWwgdHAwIGRlIE9yZ2FuaXphY2lvbiBkZSBjb21wdXRhZG9yYXM="
echo "Salida obtenida:"
../tp0 -i encoder2.txt
echo " "

echo "Test case 11: "
echo "Salida esperada: Este es un texto de ejemplo para el tp0 de Organizacion de computadoras"
echo "Salida obtenida:"
../tp0 -i output-encoder2.txt -d
echo " "