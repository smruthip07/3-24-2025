build:
	g++ -std=c++20 -o project1.out src/main.cpp src/Image.cpp

clean:
	rm project1.out
	rm project1.exe

tasks: build
	./project1.out output/part1.tga input/layer1.tga input/pattern1.tga Multiply
	./project1.out output/part2.tga input/layer2.tga input/car.tga Subtract
	./project1.out output/part3.tga input/pattern2.tga input/text.tga Multiply
	./project1.out output/part4.tga input/circles.tga input/layer2.tga Subtract
	./project1.out output/part5.tga input/layer1.tga input/pattern1.tga Overlay
	./project1.out output/part6.tga input/car.tga 0 200 0 Addition
	./project1.out output/part7.tga input/car.tga 0 1 4 Multiply
	./project1.out output/part8_r.tga input/car.tga red Seperate
	./project1.out output/part8_g.tga input/car.tga green Seperate
	./project1.out output/part8_b.tga input/car.tga blue Seperate
	./project1.out output/part9.tga input/layer_blue.tga input/layer_green.tga input/layer_red.tga Combine
	./project1.out output/part10.tga input/text2.tga Rotate