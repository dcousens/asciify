#include <array>
#include <cstdio>

#define MAX_WRITE_OUT 4096

int main () {
	std::array<char, MAX_WRITE_OUT> in;
	std::array<char, MAX_WRITE_OUT> out;

	while (true) {
		// read until EOF
		auto const read = fread(in.data(), 1, in.size(), stdin);
		if (!read) break;

		size_t j = 0;
		for (size_t i = 0; i < read; ++i) {
			auto const c = in[i];

			if (
				(c >= ' ' and c <= '~')
				or (c == '\n')
				or (c == '\t')
			) {
				out[j++] = c;
			}
		}

		if (!fwrite(out.data(), j, 1, stdout)) return 1;
	}

	return 0;
}
