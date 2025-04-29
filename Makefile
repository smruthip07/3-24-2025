build:
	g++ -std=c++20 -o project1.out src/main.cpp

run: build
	./project1.out

clean:
	rm main.o
	rm project1.out
	rm -f output/part1.tga output/part2.tga output/part3.tga output/part4.tga output/part5.tga output/part6.tga output/part7.tga output/part8_r.tga output/part8_g.tga output/part8_b.tga output/part9.tga output/part10.tga
