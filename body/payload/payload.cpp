#pragma once

namespace Payload {
  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  
  public class Program {
    void Main() {
      MessageBox.Show("Payload!", MessageBoxButtons.OK, MessageBoxIcon.Information);
    }
  }
}
