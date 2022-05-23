#include <immintrin.h>

inline __m256 v4f_sum8(__m256 ab, __m256 cd, __m256 ef, __m256 gh) {
    __m256 ad = _mm256_unpacklo_ps(ab, cd) + _mm256_unpackhi_ps(ab, cd);
    __m256 eh = _mm256_unpacklo_ps(ef, gh) + _mm256_unpackhi_ps(ef, gh);
    __m256 lo = _mm256_permute2f128_ps(ad, eh, 0b00100000);
    __m256 hi = _mm256_permute2f128_ps(ad, eh, 0b00110001);
    __m256 s = _mm256_unpacklo_ps(lo, hi) + _mm256_unpackhi_ps(lo, hi);
    return s;
}

inline __m128 v4f_sum4(__m128 a, __m128 b, __m128 c, __m128 d) {
    __m128 abl = _mm_unpacklo_ps(a, b);
    __m128 abh = _mm_unpackhi_ps(a, b);
    __m128 ab = abl + abh;
    __m128 cdl = _mm_unpacklo_ps(c, d);
    __m128 cdh = _mm_unpackhi_ps(c, d);
    __m128 cd = cdl + cdh;

    __m128 l4 = _mm_unpacklo_ps(ab, cd);
    __m128 h4 = _mm_unpackhi_ps(ab, cd);
    __m128 s4 = l4 + h4;

    __m128 s = _mm_permute_ps(s4, 0b11011000);
    return s;
}

inline __m128 v8f_sum4(__m256 a, __m256 b, __m256 c, __m256 d) {
    __m256 abl = _mm256_unpacklo_ps(a, b);
    __m256 abh = _mm256_unpackhi_ps(a, b);
    __m256 ab = abl + abh;
    __m256 cdl = _mm256_unpacklo_ps(c, d);
    __m256 cdh = _mm256_unpackhi_ps(c, d);
    __m256 cd = cdl + cdh;

    __m256 l4 = _mm256_unpacklo_ps(ab, cd);
    __m256 h4 = _mm256_unpackhi_ps(ab, cd);
    __m256 s4 = l4 + h4;

    __m128 h2 = _mm256_extractf128_ps(s4, 1);
    __m128 l2 = _mm256_castps256_ps128(s4);
    __m128 s2 = h2 + l2;
    __m128 s = _mm_permute_ps(s2, 0b11011000);
    return s;
}

inline __m256 v8f_sum8(__m256 a, __m256 b, __m256 c, __m256 d, __m256 e, __m256 f, __m256 g, __m256 h) {
    __m256 abl = _mm256_unpacklo_ps(a, c);
    __m256 abh = _mm256_unpackhi_ps(a, c);
    __m256 ab = abl + abh;
    __m256 cdl = _mm256_unpacklo_ps(b, d);
    __m256 cdh = _mm256_unpackhi_ps(b, d);
    __m256 cd = cdl + cdh;
    __m256 efl = _mm256_unpacklo_ps(e, g);
    __m256 efh = _mm256_unpackhi_ps(e, g);
    __m256 ef = efl + efh;
    __m256 ghl = _mm256_unpacklo_ps(f, h);
    __m256 ghh = _mm256_unpackhi_ps(f, h);
    __m256 gh = ghl + ghh;

    __m256 adl = _mm256_unpacklo_ps(ab, cd);
    __m256 adh = _mm256_unpackhi_ps(ab, cd);
    __m256 ad = adl + adh;
    __m256 ehl = _mm256_unpacklo_ps(ef, gh);
    __m256 ehh = _mm256_unpackhi_ps(ef, gh);
    __m256 eh = ehl + ehh;

    __m256 ahl = _mm256_blend_ps(ad, eh, 0b11110000);
    __m256 ahh = _mm256_castsi256_ps(
        _mm256_permute2f128_si256(
            _mm256_castps_si256(ad),
            _mm256_castps_si256(eh),
            0b00100001));
    __m256 ah = ahl + ahh;
    return ah;
}
inline __m256 v8f_loadu(const float* pf) {
    return _mm256_loadu_ps(pf);;
}

inline void v8f_storeu(float* pf, __m256 m) {
    _mm256_storeu_ps(pf, m);
}

const int m = 64;
const int n = 32;
void gemv4(const float *a, const float *b, const float *c, float *d) {
    const int mc = 8 * 4;
    const int nc = 8;
    static_assert(n % nc == 0, "n % nc != 0");
    static_assert((nc == 4) || (nc == 8));

    for (int j = 0; j < n; j++)
        d[j] = c[j];
    
    int i = 0;

    for (; i + mc <= m; i += mc) {
        __m256 a0 = v8f_loadu(&a[i]);
        __m256 a1 = v8f_loadu(&a[i + 8]);
        __m256 a2 = v8f_loadu(&a[i + 16]);
        __m256 a3 = v8f_loadu(&a[i + 24]);

        if (nc == 4) {
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s1 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s2 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s3 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m128 s = v8f_sum4(s0, s1, s2, s3);
                _mm_storeu_ps(&d[j], _mm_loadu_ps(&d[j]) + s);
            }
        }
        else if (nc == 8) {
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s1 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s2 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s3 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s4 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s5 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s6 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s7 = (a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8)) + (a2 * v8f_loadu(b + 16) + a3 * v8f_loadu(b + 24));
                b += 32;
                __m256 s = v8f_sum8(s0, s1, s2, s3, s4, s5, s6, s7);
                v8f_storeu(&d[j], v8f_loadu(&d[j]) + s);
            }
        }
    }

    for (; i + 16 <= m; i += 16) {
        __m256 a0 = v8f_loadu(&a[i]);
        __m256 a1 = v8f_loadu(&a[i + 8]);

        if (nc == 4) {
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s1 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s2 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s3 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m128 s = v8f_sum4(s0, s1, s2, s3);
                _mm_storeu_ps(&d[j], _mm_loadu_ps(&d[j]) + s);
            }
        }
        else if (nc == 8) {
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s1 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s2 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s3 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s4 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s5 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s6 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s7 = a0 * v8f_loadu(b) + a1 * v8f_loadu(b + 8);
                b += 16;
                __m256 s = v8f_sum8(s0, s1, s2, s3, s4, s5, s6, s7);
                v8f_storeu(&d[j], v8f_loadu(&d[j]) + s);
            }
        }
    }

    for (; i + 8 <= m; i += 8) {
        __m256 a0 = v8f_loadu(&a[i]);

        if (nc == 4) {
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = a0 * v8f_loadu(&b[0]);
                __m256 s1 = a0 * v8f_loadu(&b[8]);
                __m256 s2 = a0 * v8f_loadu(&b[16]);
                __m256 s3 = a0 * v8f_loadu(&b[24]);
                __m128 s = v8f_sum4(s0, s1, s2, s3);
                _mm_storeu_ps(&d[j], _mm_loadu_ps(&d[j]) + s);
                b += 32;
            }
        }
        else if (nc == 8) {
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = a0 * v8f_loadu(&b[0]);
                __m256 s1 = a0 * v8f_loadu(&b[8]);
                __m256 s2 = a0 * v8f_loadu(&b[16]);
                __m256 s3 = a0 * v8f_loadu(&b[24]);
                b += 32;
                __m256 s4 = a0 * v8f_loadu(&b[0]);
                __m256 s5 = a0 * v8f_loadu(&b[8]);
                __m256 s6 = a0 * v8f_loadu(&b[16]);
                __m256 s7 = a0 * v8f_loadu(&b[24]);
                b += 32;
                __m256 s = v8f_sum8(s0, s1, s2, s3, s4, s5, s6, s7);
                v8f_storeu(&d[j], v8f_loadu(&d[j]) + s);
            }
        }
    }

    for (; i + 4 <= m; i += 4) {
        if (nc == 4) {
            __m128 a0 = _mm_loadu_ps(&a[i]);
            for (int j = 0; j < n; j += nc) {
                __m128 s0 = a0 * _mm_load_ps(&b[0]);
                __m128 s1 = a0 * _mm_load_ps(&b[4]);
                __m128 s2 = a0 * _mm_load_ps(&b[8]);
                __m128 s3 = a0 * _mm_load_ps(&b[12]);
                __m128 s = v4f_sum4(s0, s1, s2, s3);
                _mm_storeu_ps(&d[j], _mm_loadu_ps(&d[j]) + s);
                b += 16;
            }
        }
        else if (nc == 8) {
            __m256 a0 = _mm256_broadcast_ps((const __m128 *)&a[i]);
            for (int j = 0; j < n; j += nc) {
                __m256 s0 = a0 * v8f_loadu(&b[0]);
                __m256 s1 = a0 * v8f_loadu(&b[8]);
                __m256 s2 = a0 * v8f_loadu(&b[16]);
                __m256 s3 = a0 * v8f_loadu(&b[24]);
                b += 32;
                __m256 s = v4f_sum8(s0, s1, s2, s3);
                v8f_storeu(&d[j], v8f_loadu(&d[j]) + s);
            }
        }
    }

    for (int j = 0; j < n; j++) {
        float s = 0;
        for (int i0 = i; i0 < m; i0++)
            s += a[i0] * *(b++);
        d[j] += s;
    }
}
