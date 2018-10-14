#include <stdio.h>
#include <string.h>
#include <exception>
#include <fstream>
#include <vector>
#include "TFile.h"
#include "TDirectory.h"
#include "TH1D.h"
#include "TSystem.h"
#include "TMacro.h"
#include <TTree.h>
#include <iostream>
#include <sstream>
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TCanvas.h"
#include <iterator>
#include <algorithm>
#include "TImage.h"
#include "TStyle.h"



using namespace std;


string GetLocation(string str)
{
     
    int i = str.rfind("_Slot_");
    string way = str.substr(0,i);  
    return way;
}

struct vectorsTree
{
  vector<double> *FEBSN;
  vector<double> *SpillTag;
  vector<double> *GTrigTag;
  vector<double> *GTrigTime;
  vector<double> *hitsChannel;
  vector<double> *hitAmpl;
  vector<double> *hitAmplRec;
  vector<double> *hitLGAmpl;
  vector<double> *hitLGAmplRec;
  vector<double> *hitHG_pe;
  vector<double> *hitLG_pe;
  vector<double> *hitToT_pe;
  vector<double> *hitCharge_pe;
  vector<double> *hitLeadTime;
  vector<double> *hitTrailTime;
  vector<double> *hitTimeDif;
  vector<double> *hitTimefromSpill;
  
};


int main ()
{
    
    int NumberOfEB = 30;
    int FEBs[19] = {0,1,2,3,4,8,9,10,11,12,16,17,18,19,20,24,25,26,27};
    
    vector<string> vFileNames;
    string sFileName;
    ifstream fList("febs_files_list.list");
    while (!fList.eof()) {
        fList >> sFileName;
        vFileNames.push_back(sFileName);
    }
    fList.close();
    
    string rootFileInput=GetLocation(vFileNames[0].c_str());
    string rootFileOutput=GetLocation (vFileNames[0].c_str());
    rootFileInput+="_all_reconstructed.root";
    //rootFileInput+="_all.root";
    rootFileOutput+="_event_display.root";
    cout << rootFileInput<<endl;
    
    TFile *FileInput = new TFile(rootFileInput.c_str());
    
    vectorsTree FEB[NumberOfEB];
    
    for (Int_t i=0;i<NumberOfEB;i++){
        FEB[i].FEBSN=0;
        FEB[i].SpillTag=0;
        FEB[i].hitsChannel=0;
        FEB[i].hitAmpl=0;
        FEB[i].hitAmplRec=0;
        FEB[i].hitLeadTime=0;
        FEB[i].GTrigTag=0;
        FEB[i].GTrigTime=0;
        FEB[i].hitLGAmpl=0;
        FEB[i].hitLGAmplRec=0;
        FEB[i].hitTrailTime=0;
        FEB[i].hitTimeDif=0;
        FEB[i].hitTimefromSpill=0;
        
        FEB[i].hitHG_pe=0;
        FEB[i].hitLG_pe=0;
        FEB[i].hitToT_pe=0;
        FEB[i].hitCharge_pe=0;
        
    }
    
    
    TTree *FEBtree[NumberOfEB];
    Long64_t nentries[NumberOfEB];
    std::fill(nentries, nentries + NumberOfEB, 0);
    
    ostringstream sFEBnum;
    string sFEB;
    
    vector<int> FEBnumbers;
    FEBnumbers.clear();
    
    
    for (Int_t ih=0; ih<NumberOfEB; ih++) {
        sFEBnum.str("");
        sFEBnum << ih;
        sFEB = "FEB_"+sFEBnum.str();
        FEBtree[ih] = (TTree*)FileInput->Get(sFEB.c_str());
        if ((TTree*)FileInput->Get(sFEB.c_str())){
            //std::cout<<sFEB<<" ";
            FEBtree[ih]->SetBranchAddress((sFEB+"_SN").c_str(),&FEB[ih].FEBSN);
            FEBtree[ih]->SetBranchAddress((sFEB+"_SpillTag").c_str(),&FEB[ih].SpillTag);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTag").c_str(),&FEB[ih].GTrigTag);
            FEBtree[ih]->SetBranchAddress((sFEB+"_GTrigTime").c_str(),&FEB[ih].GTrigTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitsChannel").c_str(),&FEB[ih].hitsChannel);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitAmpl").c_str(),&FEB[ih].hitAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLGAmpl").c_str(),&FEB[ih].hitLGAmpl);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLeadTime").c_str(),&FEB[ih].hitLeadTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTrailTime").c_str(),&FEB[ih].hitTrailTime);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimeDif").c_str(),&FEB[ih].hitTimeDif);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitTimefromSpill").c_str(),&FEB[ih].hitTimefromSpill);
            
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitAmplRecon").c_str(), &FEB[ih].hitAmplRec);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLGAmplRecon").c_str(), &FEB[ih].hitLGAmplRec);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitHG_pe").c_str(), &FEB[ih].hitHG_pe);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitLG_pe").c_str(), &FEB[ih].hitLG_pe);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitToT_pe").c_str(), &FEB[ih].hitToT_pe);
            FEBtree[ih]->SetBranchAddress((sFEB+"_hitCharge_pe").c_str(), &FEB[ih].hitCharge_pe);
            
            nentries[ih] = FEBtree[ih]->GetEntries();
            FEBtree[ih]->GetEntry(0);
            //std::cout << "Number of events = " <<FEB[ih].FEBSN->size()<<std::endl;
        }
  }
  
    double minEn = nentries[0];
    for(int i = 0; i < NumberOfEB; i++){
        if(nentries[i] < minEn && nentries[i]>0){
            minEn = nentries[i];
        }
    }
    cout << "Number of spills " << minEn << endl;

  TFile wfile(rootFileOutput.c_str(), "recreate");
  cout<<rootFileOutput<<endl;
  
  int MapCon[28][2][96];
  for (int iFEB = 0; iFEB<19; iFEB++) {
       if (FEBs[iFEB] != 12){
        sFEBnum.str("");
        sFEBnum << FEBs[iFEB];
        sFEB = "../mapping/" + sFEBnum.str() + ".txt";
        ifstream fmap(sFEB.c_str());
        //cout <<endl<< "FEB "<< FEBs[iFEB]<< " mapping"<<endl;
        int temp=0;
        while (!fmap.eof()) {
            fmap >> temp >> MapCon[FEBs[iFEB]][0][temp] >>MapCon[FEBs[iFEB]][1][temp];
            //cout<<temp<<" "<<MapCon[FEBs[iFEB]][0][temp]<<" "<<MapCon[FEBs[iFEB]][1][temp]<<endl;
        //temp++;
        }
        fmap.close();
       }
  }
  

  TH2F *EventsMap_XY = new TH2F("All_events_map_XY","All_events_map_XY",  24,0,24, 8,0,8);
  TH2F *EventsMap_YZ = new TH2F("All_events_map_YZ","All_events_map_YZ",  48,0,48, 8,0,8);
  TH2F *EventsMap_XZ = new TH2F("All_events_map_XZ","All_events_map_XZ",  24,0,24, 48,0,48);
  
  TDirectory *events2D = wfile.mkdir("events2D");
  int NumberEvDis = 10000;
  
  ostringstream sEventnum;
  string sEvent;
  TH2F *event_XY[NumberEvDis];
  for (Int_t ih=0; ih < NumberEvDis;ih++){
    sEventnum.str("");
    sEventnum << ih;
    sEvent = "event_XY"+sEventnum.str();
    event_XY[ih] = new TH2F(sEvent.c_str(),sEvent.c_str(), 24,0,24, 8,0,8);
  }
  
  TH2F *event_YZ[NumberEvDis];
  for (Int_t ih=0; ih < NumberEvDis;ih++){
    sEventnum.str("");
    sEventnum << ih;
    sEvent = "event_YZ"+sEventnum.str();
    event_YZ[ih] = new TH2F(sEvent.c_str(),sEvent.c_str(), 48,0,48, 8,0,8);
  }
  
  TH2F *event_XZ[NumberEvDis];
  for (Int_t ih=0; ih < NumberEvDis;ih++){
    sEventnum.str("");
    sEventnum << ih;
    sEvent = "event_XZ"+sEventnum.str();
    event_XZ[ih] = new TH2F(sEvent.c_str(),sEvent.c_str(), 24,0,24, 48,0,48);
  }
  
  TH1F *event_LY[NumberEvDis];
  for (Int_t ih=0; ih < NumberEvDis;ih++){
    sEventnum.str("");
    sEventnum << ih;
    sEvent = "event_LY"+sEventnum.str();
    event_LY[ih] = new TH1F(sEvent.c_str(),sEvent.c_str(),48,0,48);
  }
  Double_t energyDep[48];
  Int_t eventNum=0;
  
  bool LargehitTimeDif = 0;

  TCanvas *c1 = new TCanvas("c1","c1", 1480, 1160);
  bool SpillMised = false;
  for (Int_t subSpill = 0; subSpill<minEn; subSpill++) {
  //for (Int_t subSpill = 0; subSpill<10; subSpill++) {
        Int_t SpillNumber = subSpill;
        
        cout << "Getting Spill Number " << SpillNumber + 1 << endl;
        for (int ik = 0; ik < 19; ik++){
            FEBtree[FEBs[ik]]->GetEntry(SpillNumber);
            if (FEB[FEBs[ik]].SpillTag->back() != SpillNumber + 1){
                cout << "wtf" <<endl;
            }
            if (FEB[FEBs[ik]].SpillTag->size() < 2 ){
                cout << "NULL"<<endl;
                SpillMised = true;
                break;
            } else {
                SpillMised = false;
            }
            //cout << "FEB_"<< FEBs[ik]<< " "<< FEB[FEBs[ik]].hitCharge_pe->size()<<endl;
        }
        if (!SpillMised){
            
            
            for ( int TOFtrigger = 0; TOFtrigger < FEB[12].FEBSN->size(); TOFtrigger++){
            if (FEB[12].hitTimeDif->at(TOFtrigger) > 0 && NumberEvDis > eventNum){
                for (int ik = 0; ik < 48; ik++ )
                    energyDep[ik] = 0;
                    LargehitTimeDif = 0;
                    Int_t GTindex[2] = {0,0};
                    for (int i = 0; i < 19; i++){
                    if (FEBs[i]!=12){
                        
                        auto bounds=std::equal_range (FEB[FEBs[i]].GTrigTag->begin(), FEB[FEBs[i]].GTrigTag->end(), FEB[12].GTrigTag->at(TOFtrigger));
                        GTindex[0] = bounds.first - FEB[FEBs[i]].GTrigTag->begin();
                        GTindex[1] = bounds.second - FEB[FEBs[i]].GTrigTag->begin();
            
                        for (int check = GTindex[0]; check <  GTindex[1]; check++){
                            if (abs(FEB[12].hitTimefromSpill->at(TOFtrigger) - FEB[FEBs[i]].hitTimefromSpill->at(check)) < 100){
                                if (FEB[FEBs[i]].hitTimeDif->at(check) > 60)
                                    LargehitTimeDif = 1;
                                if ( FEBs[i] == 0 || FEBs[i] == 16){
                                    event_XY[eventNum]->Fill(MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)],MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)],FEB[FEBs[i]].hitCharge_pe->at(check));
                                    EventsMap_XY->Fill(MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)],MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)],1);
                                } else if ( FEBs[i] == 1 || FEBs[i] == 2 || FEBs[i] == 17 || FEBs[i] ==24){
                                    event_YZ[eventNum]->Fill(MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)],MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)],FEB[FEBs[i]].hitCharge_pe->at(check));
                                    EventsMap_YZ->Fill(MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)],MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)],1);
                                    if (FEB[FEBs[i]].hitCharge_pe->at(check) > 0  && FEB[FEBs[i]].hitCharge_pe->at(check) < 10000)
                                        energyDep[MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)]] += FEB[FEBs[i]].hitCharge_pe->at(check);
                            
                                } else {
                                    event_XZ[eventNum]->Fill(MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)],MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)],FEB[FEBs[i]].hitCharge_pe->at(check));
                                    EventsMap_XZ->Fill(MapCon[FEBs[i]][0][(int)FEB[FEBs[i]].hitsChannel->at(check)],MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)],1);
                                    if (FEB[FEBs[i]].hitCharge_pe->at(check) > 0  && FEB[FEBs[i]].hitCharge_pe->at(check) < 10000)
                                        energyDep[MapCon[FEBs[i]][1][(int)FEB[FEBs[i]].hitsChannel->at(check)]] += FEB[FEBs[i]].hitCharge_pe->at(check);
                                }
                            }
                    }
                }
            }
            
            for (int ik = 0; ik < 48; ik++ ){
        
                event_LY[eventNum]->Fill(ik,energyDep[ik]);
        }
        if ( LargehitTimeDif == 0) {
                c1->Clear();
            if (event_XZ[eventNum]->GetEntries()>10){
        
                c1->Divide(2,2);
        
                c1 -> cd(1);
                event_XY[eventNum]-> Draw("colorz");
        
                c1 -> cd(2);
                event_YZ[eventNum]-> Draw("colorz");
        
                c1 -> cd(3);
                event_XZ[eventNum]->Draw("colorz");
        
                c1 -> cd(4);
                event_LY[eventNum]->Draw("HIST");
        
                c1->Update();
                events2D -> cd();

                c1->Write();
            }
        }
        delete event_XY[eventNum];
        delete event_YZ[eventNum];
        delete event_XZ[eventNum];
        delete event_LY[eventNum];
        
        eventNum++;
    }
  }
 
  for (Int_t i=0;i<NumberOfEB;i++){
        FEB[i].FEBSN=0;
        FEB[i].SpillTag=0;
        FEB[i].hitsChannel=0;
        FEB[i].hitAmpl=0;
        FEB[i].hitAmplRec=0;
        FEB[i].hitLeadTime=0;
        FEB[i].GTrigTag=0;
        FEB[i].GTrigTime=0;
        FEB[i].hitLGAmpl=0;
        FEB[i].hitLGAmplRec=0;
        FEB[i].hitTrailTime=0;
        FEB[i].hitTimeDif=0;
        FEB[i].hitTimefromSpill=0;
        
        FEB[i].hitHG_pe=0;
        FEB[i].hitLG_pe=0;
        FEB[i].hitToT_pe=0;
        FEB[i].hitCharge_pe=0;
        
    }
        }    
  }
   wfile.cd();
  EventsMap_XY->Write();
  EventsMap_YZ->Write();
  EventsMap_XZ->Write();
  
     wfile.Close();
     FileInput->Close();
     return 0;
}
