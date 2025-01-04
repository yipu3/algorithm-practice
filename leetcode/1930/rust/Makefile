idx := $(shell basename $(shell dirname ${PWD}))

push:
	git add ./ && git commit -m "leetcode ${idx} in rust" && git push

build:
	cargo build

run:
	cargo fmt && cargo run
