make tp0

cd ./tests

echo "Test help command"
../tp0 -h

echo "Test version command"
../tp0 - V

echo "Test case 1: "
../tp0 -i encoder-test.txt

echo "Test case 2: "
../tp0 -i encoder-test.txt -d

echo "Test case 3: "
../tp0 -i encoder-test.txt | ../tp0 -d

echo "Test case 4: "
../tp0 -i empty-file.txt

echo "Test case 5: "
../tp0 -i empty-file.txt -d

echo "Test case 6: "
../tp0 -i bad-file.txt -d

echo "Test case 7: "
../tp0 -i binary-file.txt -d

echo "Test case 8: "
../tp0 -i not-exist-file.txt

echo "Test case 9: "
../tp0 -i not-exist-file.txt -d
