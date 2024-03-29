#ifndef __COMBINATION_WORD_H__
#define __COMBINATION_WORD_H__

#include <fstream>
using namespace std;
#define OUTPUT_FILE_NAME  ("result.txt")

class CombinationWord {
protected:
  char*       m_pCandidateChar;   //!< 候補文字群
  int         m_candidateCharNum; //!< 候補文字群の数
  bool        m_isFileOutput;     //!< ファイル出力する／しない
  ofstream    m_outputFile;       //!< ファイル出力ストリーム
  char*       m_pWorkBuffer;      //!< 作業用バッファ
  int         m_workBufferSize;   //!< 作業用バッファサイズ[Byte]

public:
  CombinationWord() 
    : m_pCandidateChar(nullptr)
    , m_candidateCharNum(0)
    , m_isFileOutput(false)
    , m_outputFile()
    , m_pWorkBuffer(nullptr)
    , m_workBufferSize(0)
  {}

  ~CombinationWord() {
    if (nullptr != m_pCandidateChar) {
      delete[] m_pCandidateChar;
      m_pCandidateChar = nullptr;
    }
    m_candidateCharNum = 0;
    if (nullptr != m_pWorkBuffer) {
      delete[] m_pWorkBuffer;
      m_pWorkBuffer = nullptr;
    }
    m_workBufferSize = 0;
    m_outputFile.close();
  }

  /*!
  * @brief 初期化
  * @param pCandidateChar     [in]  候補文字群
  * @param candidateCharNum   [in]  候補の文字群の数
  * @param isFileOutput       [in]  ファイル出力する／しない
  */
  bool  Initialize(const char* pCandidateChar, int candidateCharNum, bool isFileOutput);

  /*!
  * @brief 文字組み合わせ
  * @param digitNth    [in]  何桁目
  * @param digitMax    [in]  最大桁数
  */
  void  GenerateCombination(int digitNth, int digitMax);

protected:
  /*!
  * @brief 文字組み合わせ
  * @param digitNth    [in]  何桁目
  * @param digitMax    [in]  最大桁数
  * @param p_result    [in/out]  組み合わせ後の文字列
  */
  void  _GenerateCombination(int digitNth, int digitMax, char* p_result);

};
#endif
