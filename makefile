
clean:
	rm -rf build && mkdir -p build && cd build && conan install .. --build=missing

start:
	cd build && cmake .. && make --no-print-directory && bin/example

commit:
	git add . && git commit -m="$m"